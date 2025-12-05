/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:51 by acombier          #+#    #+#             */
/*   Updated: 2025/12/05 14:52:56 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

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
	size_t	i;
	size_t	j;
	size_t	slen1;
	size_t  slen2;

	char *joined;

	i = 0;
	j = 0;
	
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);

	joined = malloc((slen1 + slen2) + 1);
	if(!joined)
	{
		free(s1);
		return (NULL);
	}
	while(s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	
	free(s1);
	return (joined);
}

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*line;

// 	if(!s)
// 		return (NULL);
// 	if(start > ft_strlen(s))
// 	{
// 		return (malloc(1));
// 	}
// 	if(len > ft_strlen(s + start))
// 		len = ft_strlen(s + start);
// 	line = malloc((len + 1) * sizeof(char));
// 	if(!line)
// 		return (NULL);
// 	i = 0;
// 	while(i < len)
// 	{
// 		line[i] = s[start + i];
// 		i++;
// 	}
// 	line[i] = '\0';
	
// 	return (line);
	
// }
