/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:04:07 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/11/18 17:35:08 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_remainder(int fd, char *remainder);
char	*save_remainder(char *remainder);
char	*extract_line(char *remainder);

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = update_remainder(fd, remainder);
	while (remainder && !ft_strchr(remainder, '\n'))
		remainder = update_remainder(fd, remainder);
	if (remainder && *remainder)
	{
		line = extract_line(remainder);
		remainder = save_remainder(remainder);
		return (line);
	}
	free(remainder);
	remainder = NULL;
	return (NULL);
}

char	*update_remainder(int fd, char *remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (remainder);
	buffer[bytes_read] = '\0';
	temp = ft_strjoin(remainder, buffer);
	free(remainder);
	return (temp);
}

char	*extract_line(char *remainder)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!remainder)
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	next_line = (char *)ft_calloc(sizeof(char), (i + 1));
	if (!next_line)
		return (NULL);
	while (i-- > 0)
		next_line[i] = remainder[i];
	return (next_line);
}

char	*save_remainder(char *remainder)
{
	char	*new_remainder;
	int		i;

	i = 0;
	if (!remainder)
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = ft_strdup(remainder + i + 1);
	free(remainder);
	return (new_remainder);
}
