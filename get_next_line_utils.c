/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriencombier <adriencombier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:21:26 by acombier          #+#    #+#             */
/*   Updated: 2025/11/28 12:39:19 by adriencombi      ###   ########.fr       */
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


char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
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



int main(void)
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
}