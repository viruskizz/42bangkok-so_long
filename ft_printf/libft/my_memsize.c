/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:44:36 by araiva            #+#    #+#             */
/*   Updated: 2022/03/25 20:44:37 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	my_memsize(void *ptr)
{
	char	*str;
	size_t	n;

	n = 0;
	str = (char *) ptr;
	while (*str++)
		n++;
	return (n);
}
