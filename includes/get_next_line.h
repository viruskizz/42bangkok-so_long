/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:04:11 by araiva            #+#    #+#             */
/*   Updated: 2022/03/13 15:06:06 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_file
{
	char	*str;
	char	*line;
	int		is_end;
}	t_file;

char	*get_next_line(int fd);
char	*my_substr(char *str, int start, int end);
char	*my_strcat(char *s1, char *s2);
char	*my_realloc(char *str, int size);
int		my_strlen(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

#endif
