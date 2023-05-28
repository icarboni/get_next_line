/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:53:39 by icarboni          #+#    #+#             */
/*   Updated: 2022/10/05 16:58:26 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_static(char *left_buf, int len)
{
	char	*next_left;

	next_left = ft_substr(left_buf, (len + 1), (ft_strlen(left_buf) - len - 1));
	free(left_buf);
	return (next_left);
}

char	*ft_get_line(char *left_buf)
{
	char	*line;
	int		i;

	i = 0;
	while (left_buf[i] != '\n' && left_buf[i] != '\0')
		i++;
	if (left_buf[i] == '\n')
		i++;
	line = ft_substr(left_buf, 0, i);
	return (line);
}

char	*ft_get_buf(int fd, char *left_buf)
{	
	char	buffer[BUFFER_SIZE + 1];
	int		found;
	int		i;

	found = 0;
	if (ft_strchr(left_buf, '\n') != NULL)
		found = 1;
	i = BUFFER_SIZE;
	while (found == 0 && i == BUFFER_SIZE)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		if (i == 0 && !left_buf)
			return (NULL);
		buffer[i] = '\0';
		left_buf = ft_strjoin(left_buf, buffer);
		if (ft_strchr(buffer, '\n') != NULL)
			found = 1;
	}
	return (left_buf);
}

char	*get_next_line(int fd)
{
	static char			*left_buf[1024];
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_buf[fd] = ft_get_buf(fd, left_buf[fd]);
	if (!left_buf[fd])
	{
		free(left_buf[fd]);
		return (NULL);
	}
	line = ft_get_line(left_buf[fd]);
	if (!line)
		return (NULL);
	left_buf[fd] = ft_static(left_buf[fd], ft_strlen(line) - 1);
	if (left_buf[fd][0] == '\0')
	{
		free(left_buf[fd]);
		left_buf[fd] = NULL;
	}
	if (line[0] == '\0')
		return (NULL);
	return (line);
}
