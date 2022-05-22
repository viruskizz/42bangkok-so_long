/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:23:07 by araiva            #+#    #+#             */
/*   Updated: 2022/03/20 18:23:09 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>

char	*my_realloc(char *str, int size)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	ptr[0] = 0;
	if (!str)
		return (ptr);
	i = -1;
	while (str[++i])
		ptr[i] = str[i];
	ptr[i] = '\0';
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (ptr);
}

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*my_strcat(char *s1, char *s2)
{
	int		i;

	s1 = my_realloc(s1, my_strlen(s1) + my_strlen(s2) + 1);
	if (!s1)
		return (NULL);
	i = my_strlen(s1);
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}

char	*my_substr(char *str, int start, int end)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (NULL);
	while (start < end)
		dest[i++] = str[start++];
	dest[i] = '\0';
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (dest);
}
