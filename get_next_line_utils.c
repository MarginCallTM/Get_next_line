/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriencombier <adriencombier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:21:26 by acombier          #+#    #+#             */
/*   Updated: 2025/11/28 11:12:58 by adriencombi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*joined;

	if (!s1)
	{
    	s1 = malloc(1);
    	if (!s1)
      	  return NULL;
   	 	s1[0] = '\0';
	}
	if(!s2)
		return (NULL);
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	joined = malloc(slen1 + slen2 + 1);
	if(!joined)
		return(NULL);
	ft_strcpyjoin(joined, s1, s2);
	return (joined);
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


/*int main(void)
{
	printf("%zu", ft_strlen("Hello Earth!"));
	char	s1[] = "\nouioui ";
	char	s2[] = "Baguette\n";

	int	c = 'H';
	char	s3[] = "Petit Honey\n";

	char	s4[] = "Les saucisses sont cuites!\n";
	size_t len = 13;

	ft_strjoin(s1, s2);
	ft_strchr(s3, c);

	printf("%s", ft_strjoin(s1, s2));
	printf("%s", ft_strchr(s3, c));
	printf("%s", ft_substr(s4, 0, 12));

	return(0);
}*/