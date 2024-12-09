/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:21:34 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/12/09 18:30:18 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Reads data from a file descriptor into a buffer.
(fd) > The file descriptor to read from.
(buffer) > The buffer where the data will be stored.
return (ssize_t) > The number of bytes read, or -1 if an error occurs. */
ssize_t	ft_read_file(int fd, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		buffer[0] = '\0';
	else if (bytes_read > 0)
		buffer[bytes_read] = '\0';
	return (bytes_read);
}

/* Joins two strings into one new string.
(s1) > The first string.
(s2) > The second string.
return (char *) > A new string containing the concatenated result, or NULL
if memory allocation fails. */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2[j])
	{
		result[i++] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	result[i] = '\0';
	return (result);
}

/* Checks if the buffer contains a newline character and processes it.
(buffer) > The buffer to check for a newline character.
return (int) > 1 if a newline is found and processed, 0 otherwise. */
int	ft_new_line(char *buffer)
{
	char	*newline;
	size_t	i;

	newline = ft_strchr(buffer, '\n');
	if (newline)
	{
		i = 0;
		newline++;
		while (*newline)
			buffer[i++] = *newline++;
		buffer[i] = '\0';
		return (1);
	}
	i = 0;
	while (buffer[i])
		buffer[i++] = 0;
	return (0);
}

/* Searches for the first occurrence of a character in a string.
(s) > The string to search in.
(c) > The character to search for.
return (char *) > A pointer to the first occurrence of the character, or NULL
if not found. */
char	*ft_strchr(char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}

/* Calculates the length of a string up to a newline or the null terminator.
(str) > The string to measure the length of.
return (ssize_t) > The length of the string up to the first newline,
or the full length if no newline is found. */
ssize_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
