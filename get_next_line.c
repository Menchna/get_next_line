/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:13:49 by armkrtch          #+#    #+#             */
/*   Updated: 2025/05/01 21:13:55 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join_free(char *res, char *buff)
{
	char	*temp;

	temp = ft_strjoin(res, buff);
	free(res);
	return (temp);
}

static char	*ft_trim_buffer(char *buffer)
{
	char	*newline;
	char	*rest;

	newline = ft_strchr(buffer, '\n');
	if (!newline)
	{
		free(buffer);
		return (NULL);
	}
	rest = ft_strndup(newline + 1, ft_strlen(newline + 1));
	free(buffer);
	return (rest);
}

static char	*ft_set_line(char *buffer)
{
	int	i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (ft_strndup(buffer, i));
}

static char	*ft_fill_line_buffer(int fd, char *str)
{
	t_buff	buff_data;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	buff_data.buff = malloc(BUFFER_SIZE + 1);
	if (!buff_data.buff)
		return (NULL);
	buff_data.read_size = 1;
	while (!ft_strchr(str, '\n') && buff_data.read_size > 0)
	{
		buff_data.read_size = read(fd, buff_data.buff, BUFFER_SIZE);
		if (buff_data.read_size < 0)
		{
			free(buff_data.buff);
			free(str);
			return (NULL);
		}
		buff_data.buff[buff_data.read_size] = '\0';
		str = ft_join_free(str, buff_data.buff);
	}
	return (free(buff_data.buff), str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_fill_line_buffer(fd, buffer);
	if (!buffer || *buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_set_line(buffer);
	buffer = ft_trim_buffer(buffer);
	return (line);
}

// int main(void)
// {
//     int fd = open("get_next_line.c", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Failed to open file");
//         return 1;
//     }
// 	char* line = get_next_line(fd);
// 	printf("%s", line);

//     close(fd);
//     return 0;
// }
