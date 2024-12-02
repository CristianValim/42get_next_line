/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:21:34 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/12/02 16:02:08 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/* int	main(void)
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
} */
