/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:11:15 by gjacinta          #+#    #+#             */
/*   Updated: 2021/11/28 17:24:59 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*delete_line(char *memory)
{
	char	*new_memory;
	size_t	i;
	size_t	c;

	if (memory == NULL)
		return (NULL);
	i = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\0')
	{
		free(memory);
		return (NULL);
	}
	new_memory = malloc(sizeof(char) * (ft_strlen(memory) - i + 1));
	if (new_memory == NULL)
		return (NULL);
	c = 0;
	i++;
	while (memory[i] != '\0')
		new_memory[c++] = memory[i++];
	new_memory[c] = '\0';
	free(memory);
	return (new_memory);
}

char	*clear_line(char	*memory)
{
	char	*line;
	int		i;
	int		count;

	i = 0;
	if (memory[i] == '\0')
		return (NULL);
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	count = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
		line[count++] = memory[i++];
	if (memory[i] == '\n')
		line[count++] = memory[i++];
	line[count] = '\0';
	return (line);
}

char	*read_buffer(int fd, char *memory)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		memory = ft_strjoin(memory, buffer);
		if (find_new_line(memory))
			break ;
	}
	free(buffer);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char		*memory[_SC_OPEN_MAX];
	char			*final_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	memory[fd] = read_buffer(fd, memory[fd]);
	if (memory[fd] == NULL)
		return (NULL);
	final_line = clear_line(memory[fd]);
	memory[fd] = delete_line(memory[fd]);
	return (final_line);
}
