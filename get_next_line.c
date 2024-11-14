/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:52:46 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/11/14 15:31:29 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_index = 0;
	static int	bytes_read = 0;
	char		*line;
	int			line_index;

	while (1)
	{
		if (buffer_index >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (bytes_read <= 0)
				return (NULL);
		}
		
	};
}

int	main(void)
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}