/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:41:50 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/12/09 18:27:41 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Reads the next line from a file descriptor.
(fd) > The file descriptor to read from.
return (char *) > A string containing the next line, or NULL if an error occurs 
or EOF is reached. */
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

/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*result;

	s1 = "Hello, ";
	s2 = "world!";
	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Resultado: %s\n", result);
		free(result);
	}
	else
	{
		printf("Erro ao alocar memória.\n");
	}
	return (0);
}
*/