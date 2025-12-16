/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriencombier <adriencombier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:56:24 by adriencombi       #+#    #+#             */
/*   Updated: 2025/12/16 12:45:13 by adriencombi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*alloc_line_and_copy(const char *str, int len);
static void	copy_remaining_buffer(char *buffer, int start);

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_init_buffer_line(fd, buffer);
	if (!str)
		return (NULL);
	str = ft_extract_line(str);
	ft_clean_buffer(buffer);
	return (str);
}



char	*ft_extract_line(char *str)
{
	int	i = 0;

	if (!str || str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (alloc_line_and_copy(str, i));
}


static char	*alloc_line_and_copy(const char *str, int len)
{
	char	*line;
	int		i = 0;

	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	free((void *)str);
	return (line);
}



char	*ft_clean_buffer(char *buffer)
{
	int	i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		buffer[0] = '\0';
		return (NULL);
	}
	copy_remaining_buffer(buffer, i + 1);
	return (buffer);
}

static void	copy_remaining_buffer(char *buffer, int start)
{
	int	j = 0;

	while (buffer[start])
		buffer[j++] = buffer[start++];
	buffer[j] = '\0';
}

