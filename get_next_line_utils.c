/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:21:26 by acombier          #+#    #+#             */
/*   Updated: 2025/11/25 12:44:14 by acombier         ###   ########.fr       */
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


char	*ft_strjoin(char *s1, char *s2)
{
	
}

char	*ft_strchr(const char *s, int c)
{
	
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	
}
