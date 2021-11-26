/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:40:57 by gjacinta          #+#    #+#             */
/*   Updated: 2021/11/25 16:13:02 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*delete_clear_line(char *final_line)
{
	char	*new_save_line;
	size_t	i;
	size_t	c;

	if (final_line == NULL)
		return (NULL);
	i = 0;
	while (final_line[i] != '\0' && final_line[i] != '\n')
		i++;
	if (final_line[i] == '\0')
	{
		free(final_line);
		return (NULL);
	}
	new_save_line = malloc(sizeof(char) * (ft_strlen(final_line) - i + 1));
	if (new_save_line == NULL)
		return (NULL);
	c = 0;
	i++;
	while (final_line[i] != '\0')
		new_save_line[c++] = final_line[i++];
	new_save_line[c] = '\0';
	free(final_line);
	return (new_save_line);
}

char	*clear_save_line(char *final_line)
{
	char	*line;
	int		i;
	int		c;

	i = 0;
	if (final_line[i] == '\0')
		return (NULL);
	while (final_line[i] != '\0' && final_line[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	c = 0;
	while (final_line[i] != '\0' && final_line[i] != '\n')
		line[c++] = final_line[i++];
	if (final_line[i] == '\n')
		line[c++] = final_line[i++];
	line[c] = '\0';
	return (line);
}

char	*buffer_scan(int fd, char *final_line)
{
	char	*buffer;
	int		bytes_scan;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bytes_scan = 1;
	while (bytes_scan > 0)
	{
		bytes_scan = read(fd, buffer, BUFFER_SIZE);
		if (bytes_scan == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_scan] = '\0';
		final_line = ft_new_strjoin(final_line, buffer);
		if (has_new_line(final_line))
			break ;
	}
	free(buffer);
	return (final_line);
}

char	*get_next_line(int fd)
{
	char			*cut_line;
	static char		*final_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	final_line = buffer_scan(fd, final_line);
	if (final_line == NULL)
		return (NULL);
	cut_line = clear_save_line(final_line);
	final_line = delete_clear_line(final_line);
	return (cut_line);
}