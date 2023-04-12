/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_control.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 00:03:17 by jihokim           #+#    #+#             */
/*   Updated: 2021/03/30 00:03:19 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_CONTROL_H
# define SCENE_CONTROL_H

int				scene_prepare(int argc, char **argv, t_vars *v_);
int				key_hook(int keycode, t_vars *v_);
int				terminate_minirt(t_vars *v_);

#endif
