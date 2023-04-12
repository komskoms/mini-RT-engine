/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:15:06 by jihokim           #+#    #+#             */
/*   Updated: 2021/04/11 13:15:12 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# if defined(__APPLE__)
#  define KEYCODE_R 15
#  define KEYCODE_P 35
#  define KEYCODE_M 46
#  define KEYCODE_BRACKET_L 33
#  define KEYCODE_BRACKET_R 30
#  define KEYCODE_TAB 48
#  define KEYCODE_ESC 53
#  define KEYCODE_LEFT 123
#  define KEYCODE_RIGHT 124
#  define KEYCODE_DOWN 125
#  define KEYCODE_UP 126

# elif defined(__linux__)
#  define KEYCODE_R 114
#  define KEYCODE_P 112
#  define KEYCODE_M 109
#  define KEYCODE_TAB 65289
#  define KEYCODE_ESC 65307
#  define KEYCODE_LEFT 65361
#  define KEYCODE_RIGHT 65363
#  define KEYCODE_DOWN 65364
#  define KEYCODE_UP 65362
# endif

#endif
