/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriencombier <adriencombier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:42:19 by qdescomb          #+#    #+#             */
/*   Updated: 2025/12/06 15:23:35 by adriencombi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


int main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	free(str);

	close(fd);
	return (1);
}
