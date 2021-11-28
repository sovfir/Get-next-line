/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacinta <gjacinta@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:27:41 by gjacinta          #+#    #+#             */
/*   Updated: 2021/11/28 16:30:04 by gjacinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *memory, char *buffer)
{
	char	*new;
	int		i;

	if (memory == NULL)
	{
		memory = malloc(sizeof(char) * 1);
		if (memory == NULL)
			return (NULL);
		memory[0] = '\0';
	}
	if (buffer == NULL)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(memory) + ft_strlen(buffer) + 1));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, memory, (ft_strlen(memory) + 1));
	i = ft_strlen(new);
	ft_memcpy(&new[i], buffer, (ft_strlen(buffer) + 1));
	free(memory);
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;

	if (dest == src || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	tmp_dest = (char *) dest;
	tmp_src = (const char *) src;
	while (n--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}

int	find_new_line(char *memory)
{
	int	i;

	if (memory == NULL)
		return (0);
	i = 0;
	while (memory[i])
	{
		if (memory[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
