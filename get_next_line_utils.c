/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:21:26 by acombier          #+#    #+#             */
/*   Updated: 2025/12/02 10:30:13 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *stash, char *buff)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*joined;
	
	i = 0;
	if(!stash || !buff)
		return (NULL);
	total_len = ft_strlen(stash) + ft_strlen(buff);
	joined = malloc(total_len + 1);
	if(!joined)
		return (NULL);
	while(stash[i])
	{
		joined[i] = stash[i];
		i++;
	}
	j = 0;
	while(buff[j])
	{
		joined[i + j] = buff[j];
		j++;
	}
	joined[i + j] = '\0';
	return(joined);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int	main(void)
{
	//printf("%zu", ft_strlen("Hello Earth!"));
	char s1[] = "ouioui ";
	char s2[] = "Baguette\n";

	printf("%s", ft_strjoin(s1, s2));

	// int c = '\n';
	// char s3[] = "Petit Honey\n";

	// char s4[] = "Les saucisses sont cuites!\n";
	// size_t len = 13;

	// ft_strjoin(s1, s2);
	//ft_strchr(s3, c);

	// printf("%s", ft_strjoin(s1, s2));
	// printf("%s", ft_strchr(s3, c));
	// printf("%s", ft_substr(s4, 0, 12));

	return (0);
}