/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriencombier <adriencombier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:13:07 by acombier          #+#    #+#             */
/*   Updated: 2025/12/16 12:46:17 by adriencombi      ###   ########.fr       */
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

char	*ft_init_buffer_line(int fd, char *buffer);
char	*ft_clean_buffer(char *buffer);
char	*ft_extract_line(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char 	*ft_strchr(char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);

#endif