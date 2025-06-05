/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                      :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:59 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/02/07 12:49:07 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_free(char *buf, char *remain)
{
	if (buf)
		free(buf);
	if (remain)
		free(remain);
	return (NULL);
}

static void	set_line(char **last, char *first)
{
	char	*line;
	int		i;

	i = 0;
	while ((*last)[i] != '\n' && (*last)[i] != '\0')
		i++;
	if ((*last)[i] == '\n')
	{
		line = ft_substr(*last, 0, i + 1);
		if (!line)
		{
			free(*last);
			*last = NULL;
			return ;
		}
		ft_strcpy(first, *last + i + 1);
	}
	else
	{
		line = ft_strdup(*last);
		first[0] = '\0';
	}
	free(*last);
	*last = line;
}

static char	*fill_line(int fd, char *left, char *buffer)
{
	int		bytes;
	char	*tmp;
	char	*result;

	result = ft_strdup(left);
	while (!ft_strchr(result, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free(buffer, result));
		if (*result == '\0' && bytes == 0)
			return (ft_free(buffer, result));
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		tmp = ft_strjoin(result, buffer);
		free(result);
		result = tmp;
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	line[BUFFER_SIZE + 1];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	new_line = fill_line(fd, line, buffer);
	if (!new_line)
	{
		line[0] = '\0';
		return (NULL);
	}
	set_line(&new_line, line);
	return (new_line);
}
