/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:14:20 by acombier          #+#    #+#             */
/*   Updated: 2025/12/04 16:15:26 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*ft_extract_line(char *line_buffer)
{
	char	*line;
	ssize_t	i;
	
	i = 0;
	while(line_buffer[i] != '\n' || line_buffer[i] != '\0')
	{
		i++;
	}
	if(line_buffer[i] == '\0' || line_buffer[1] == '\0')
	{
		return (NULL);
	}
	line = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if(*line == 0)
	{
		line = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (line);
}

char	*ft_clean_buffer(char *line_buffer)
{
	
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char	*line;
	ssize_t	bytes_read;

	bytes_read = 1;
	line = ft_strdup(buffer);
	while(bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read == -1)
			//FREE LINE + RESET BUFFER
			return (NULL);
		buffer[bytes_read] = '\0';
		if(!line)
			line = ft_strdup("");
		line = ft_strjoin(line, buffer);
	}
	line = ft_extract_line(line);
	ft_clean_buffer(buffer);
	
	return (line);
	
	
}

int main(void)
{
	int	fd;
	char	*line;
	
	fd = open("text.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("Erreur de lecture de fichier");
		return (1);
	}
	while(line = get_next_line((fd) != NULL))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}