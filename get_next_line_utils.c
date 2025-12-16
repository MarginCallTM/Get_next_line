/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriencombier <adriencombier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:51 by acombier          #+#    #+#             */
/*   Updated: 2025/12/16 12:45:47 by adriencombi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_init_buffer_line(int fd, char *buffer)
{
	char	*line;
	ssize_t	bytes_read;

	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(line, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;
	i = 0;
	
	while(str[i])
	{
		i++;
	}
	
	return (i);
}

char	*ft_strdup(const char *src)
{
	int	i;
	char	*dest;
	
	i = 0;
	if(!src)
		return (NULL);
	while(src[i])
	{
		i++;
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;

	if (!str)
		return (NULL);
	i = 0;
	while(str[i])
	{
		if(str[i] == (char)c)
		{
			return ((char *)(&str[i]));
		}
		i++;
	}
	if(str[i] == (char)c)
		return ((char *) &str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strdup(s2));
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	free(s1);
	return (new);
}
