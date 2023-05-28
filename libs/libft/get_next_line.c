/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:46:38 by coder             #+#    #+#             */
/*   Updated: 2023/03/28 21:12:20 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	buffer = alloc_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = alloc_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}

char	*alloc_buffer(int fd, char *buffer)
{
	char	*alloc;
	size_t	bytes;

	alloc = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!alloc)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, alloc, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		alloc[bytes] = '\0';
		buffer = ft_strjoin(buffer, alloc);
		free(alloc);
		if (!buffer)
			return (NULL);
		alloc = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!alloc)
			return (NULL);
	}
	free(alloc);
	return (buffer);
}

char	*alloc_line(char *buffer)
{
	char	*line;
	size_t	len;

	if (!*buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	line = ft_calloc(sizeof(char), len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, len);
	if (buffer[len] == '\n')
		line[len] = '\n';
	line[len] = '\0';
	return (line);
}

char	*update_buffer(char *buffer)
{
	char	*new;
	size_t	len;

	if (!buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (!buffer[len])
	{
		free(buffer);
		return (NULL);
	}
	new = ft_calloc(sizeof(char), ft_strlen(buffer) - len - 1);
	if (!new)
	{
		free(buffer);
		return (NULL);
	}
	ft_strlcpy(new, &buffer[len], ft_strlen(buffer) - len);
	free(buffer);
	return (new);
}
