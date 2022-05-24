/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:07:17 by tsomsa            #+#    #+#             */
/*   Updated: 2022/05/24 08:07:18 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# ifdef __linux__

# else
#  define KEY_SPACE			49
#  define KEY_ESC			53
#  define KEY_LEFT			123
#  define KEY_RIGHT			124
#  define KEY_UP			126
#  define KEY_DOWN			125
#  define KEY_A				0
#  define KEY_S				1
#  define KEY_D				2
#  define KEY_W				13
# endif

#endif
