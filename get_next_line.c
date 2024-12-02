/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:41:50 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/12/02 16:05:41 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	bytes_read = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (*buffer || bytes_read > 0)
	{
		if (!*buffer)
		{
			bytes_read = ft_read_file(fd, buffer);
			if (bytes_read < 0)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
		}
		line = ft_strjoin(line, buffer);
		if (ft_new_line(buffer))
			break ;
	}
	return (line);
}
