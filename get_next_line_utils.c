#include "get_next_line.h"

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

char	*ft_new_strjoin(char *save_line, char *rd_buffer)
{
	char	*new;
	int		i;

	if (save_line == NULL)
	{
		save_line = malloc(sizeof(char) * 1);
		if (save_line == NULL)
			return (NULL);
		save_line[0] = '\0';
	}
	if (rd_buffer == NULL)
		return (NULL);
	new = malloc(sizeof(char)
			* (ft_strlen(save_line) + ft_strlen(rd_buffer) + 1));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, save_line, (ft_strlen(save_line) + 1));
	i = ft_strlen(new);
	ft_memcpy(&new[i], rd_buffer, (ft_strlen(rd_buffer) + 1));
	free(save_line);
	return (new);
}

int	has_new_line(char *save_line)
{
	int	i;

	if (save_line == NULL)
		return (0);
	i = 0;
	while (save_line[i] != '\0')
	{
		if (save_line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}