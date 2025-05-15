/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:25:16 by armkrtch          #+#    #+#             */
/*   Updated: 2025/04/27 19:17:32 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_join_free(char *res, char *buff)
{
	char	*temp;

	temp = ft_strjoin(res, buff);
	free(res);
	if (!temp)
		return (NULL);
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

	if (!buffer || buffer[0] == '\0')
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
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer[fd])
			free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_fill_line_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_set_line(buffer[fd]);
	buffer[fd] = ft_trim_buffer(buffer[fd]);
	return (line);
}

// int main(void)
// {
//     int fd1 = open("get_next_line.c", O_RDONLY);
//     int fd2 = open("get_next_line.c", O_RDONLY);

//     if (fd1 < 0 || fd2 < 0)
//     {
//         perror("Failed to open file(s)");
//         return 1;
//     }

//     char *line1 = NULL;
//     char *line2 = NULL;

//     while (1)
//     {
//         line1 = get_next_line(fd1);
//         if (line1)
//         {
//             printf("File1: %s", line1);
//             free(line1);
//         }

//         line2 = get_next_line(fd2);
//         if (line2)
//         {
//             printf("File2: %s", line2);
//             free(line2);
//         }

//         if (!line1 && !line2)
//             break;
//     }

//     close(fd1);
//     close(fd2);
//     return 0;
// }
