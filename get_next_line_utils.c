/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:21:34 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/11/18 17:36:15 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!joined_str)
		return (NULL);
	ft_strcpy(joined_str, s1);
	ft_strcat(joined_str, s2);
	return (joined_str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*zero_setted;
	size_t			i;

	i = 0;
	zero_setted = malloc(nmemb * size);
	if (!zero_setted)
		return (NULL);
	while (i < nmemb * size)
	{
		zero_setted[i++] = 0;
	}
	return (zero_setted);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_start);
}

char	*ft_strdup(const char *src)
{
	char	*result;
	char	*duplicated;
	int		src_length;

	result = NULL;
	duplicated = result;
	src_length = ft_strlen(src);
	result = ft_calloc(src_length + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	while (*src)
		*duplicated++ = *src++;
	*duplicated = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}
