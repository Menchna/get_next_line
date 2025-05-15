/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:20:35 by armkrtch          #+#    #+#             */
/*   Updated: 2025/04/27 19:15:46 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_buff
{
	char	*buff;
	ssize_t	read_size;
}	t_buff;

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strndup(const char *s, size_t n);
char	*get_next_line(int fd);

#endif
