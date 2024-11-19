/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:41:50 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/11/19 15:41:51 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_remainder(char *remainder, char *buffer);
char	*save_remainder(char *remainder);
char	*extract_line(char *remainder);

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_count;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_count = 1;
	while (read_count > 0)
	{
		if (*stash)
		{
			line = update_remainder(line, stash);
			if (line && ft_strchr(line, '\n'))
				break ;
		}
		read_count = read(fd, stash, BUFFER_SIZE);
		if (read_count == -1)
			return (free(line), NULL);
		stash[read_count] = '\0';
	}
	if (line)
	{
		temp = line;
		line = extract_line(line);
		free(temp);
		if (*stash)
			ft_strcpy(stash, save_remainder(stash));
	}
	return (line);
}

char	*update_remainder(char *remainder, char *buffer)
{
	char	*new_remainder;
	size_t	len_remainder;
	size_t	len_buffer;

	len_remainder = remainder ? ft_strlen(remainder) : 0;
	len_buffer = ft_strlen(buffer);
	new_remainder = (char *)malloc(len_remainder + len_buffer + 1);
	if (!new_remainder)
		return (NULL);
	if (remainder)
	{
		ft_strcpy(new_remainder, remainder);
		free(remainder);
	}
	ft_strcpy(new_remainder + len_remainder, buffer);
	return (new_remainder);
}

char	*save_remainder(char *remainder)
{
	char	*new_remainder;
	char	*nl_pos;

	nl_pos = ft_strchr(remainder, '\n');
	if (!nl_pos)
		return (NULL);
	new_remainder = ft_strdup(nl_pos + 1);
	return (new_remainder);
}

char	*extract_line(char *remainder)
{
	char *next_line;
	int i;

	i = 0;
	if (!remainder)
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	next_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!next_line)
		return (NULL);
	next_line[i] = '\0';
	while (i-- > 0)
		next_line[i] = remainder[i];
	return (next_line);
}