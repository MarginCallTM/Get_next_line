/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:42:19 by qdescomb          #+#    #+#             */
/*   Updated: 2025/12/05 15:51:34 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


int main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	free(str);
	i++;

	close(fd);
	return (1);
}