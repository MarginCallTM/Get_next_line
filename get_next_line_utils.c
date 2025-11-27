/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriencombier <adriencombier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:21:26 by acombier          #+#    #+#             */
/*   Updated: 2025/11/27 18:05:14 by adriencombi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*joined;

	if(!s1 || !s2)
		return (NULL);
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	joined = malloc(slen1 + slen2 + 1);
	if(!joined)
		return(NULL);
	ft_strcpyjoin(joined, s1, s2);
	return (joined);
}

static void	ft_strcpyjoin(char *dest, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;

	while(s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while(s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';	
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while(s[i])
	{
		if(s[i] == (char)c)
			return((char *)(s + i));
		i++;
	}
	if((char)c == '\0')
		return((char *)(s + i));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;

	if(!s)
		return(NULL);
	slen = ft_strlen(s);
	if(start >= slen)
	{
		substr = malloc(1);
		if(!substr)
			return(NULL);
		substr[0] = '\0';
		return (substr);
	}
	if((slen - start) < len)
		len = slen - start;
	substr = malloc(len + 1);
	if(!substr)
		return (NULL);
	ft_strncpy_substr(substr, s, start, len);
	return(substr);
}
static	void	ft_strncpy_substr(char *dest, const char *src, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while(i < len)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
}