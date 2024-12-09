/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:41:50 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/12/09 18:40:14 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Reads the next line from a file descriptor.
(fd) > The file descriptor to read from.
return (char *) > A string containing the next line, or NULL if an error occurs 
or EOF is reached. */
char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	bytes_read = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	while (*buffer[fd] || bytes_read > 0)
	{
		if (!*buffer[fd])
		{
			bytes_read = ft_read_file(fd, buffer[fd]);
			if (bytes_read < 0)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
		}
		line = ft_strjoin(line, buffer[fd]);
		if (ft_new_line(buffer[fd]))
			break ;
	}
	return (line);
}
