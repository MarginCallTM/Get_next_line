/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriencombier <adriencombier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:21:24 by acombier          #+#    #+#             */
/*   Updated: 2025/11/28 12:16:16 by adriencombi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *extract_line(char *stash)
{
    int     i;
    char    *line;

    if(!stash || stash[0] == '\0')
        return (NULL);
    i = 0;
    while(stash[i] && stash[i] != '\n')
    {
        i++;
    }
    if(stash[i] == '\n')
        i++;
    line = ft_substr(stash, 0 , i);
    return (line);
}

static char *update_stash(char *stash)
{
    int     i;
    char    *new_stash;

    if(!stash)
        return (NULL);
    i = 0;
    while(stash[i] && stash[i] != '\n')
    {
        i++;
    }
    if(!stash[i])
    {
        free(stash);
        return (NULL);
    }
    i++;
    new_stash = ft_substr(stash, i, ft_strlen(stash) - i);
    free (stash);
    return (new_stash);
}


char    *get_next_line(int fd)
{
    static char *stash;
    char    *line;
    char static    *buffer;
    int bytes_read;
    char    *tmp; 

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return (NULL);
    bytes_read = 1;
    while(stash == NULL || (!ft_strchr(stash, '\n') && bytes_read > 0))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read < 0)
        { 
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        tmp = stash;
        stash = ft_strjoin(stash, buffer);
        free(tmp);
    }
    free(buffer);
    line = extract_line(stash);
    stash = update_stash(stash);
    return (line);
}
