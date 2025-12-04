/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:13:07 by acombier          #+#    #+#             */
/*   Updated: 2025/12/04 15:24:54 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
static char 	*ft_strchr(char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif