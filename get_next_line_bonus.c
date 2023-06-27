/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:01:42 by iwaslet           #+#    #+#             */
/*   Updated: 2023/06/27 18:34:30 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*grab_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_calloc (sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_letgo(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

char	*new_buffer(char *str)
{
	char	*new_buffer;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_letgo(str));
	new_buffer = ft_calloc (ft_strlen(str) - (i));
	if (!new_buffer)
		return (ft_letgo(str));
	while (str[i])
	{
		i++;
		new_buffer[j] = str[i];
		j++;
	}
	free(str);
	return (new_buffer);
}

char	*read_it(char *temp, char *buffer, int fd)
{
	int	n;

	n = 1;
	while (n > 0)
	{
		n = read (fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			if (temp)
				temp = ft_letgo(temp);
			return (ft_letgo(buffer));
		}
		buffer[n] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (!temp)
			return (ft_letgo(buffer));
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*buffer;
	char		*line;

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	if (!temp[fd])
		temp[fd] = ft_calloc (1);
	buffer = ft_calloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	temp[fd] = read_it(temp[fd], buffer, fd);
	if (!temp[fd])
		return (NULL);
	free(buffer);
	line = grab_line(temp[fd]);
	temp[fd] = new_buffer(temp[fd]);
	return (line);
}
