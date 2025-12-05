/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:44:34 by acombier          #+#    #+#             */
/*   Updated: 2025/12/05 16:42:09 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_init_buffer_line(int fd, char *buffer)
{
	char	*line;
	ssize_t	bytes_read;

	line = NULL;
	bytes_read = 1;
	while ((!ft_strchr(buffer, '\n') && bytes_read > 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (!line)
		{
			line = ft_strdup("");
		}
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

char	*ft_clean_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(buffer) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[j] = buffer[i];
		j++;
		i++;
	}
	str[j] = '\0';
	i = 0;
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_extract_line(char *str)
{
	char	*line;
	ssize_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	
	free(str);
	return (line);

}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_init_buffer_line(fd, buffer);
	str = ft_extract_line(str);
	ft_clean_buffer(buffer);
	if (!ft_clean_buffer(buffer))
	{
		free(str);
		return (NULL);
	}
	return (str);
}