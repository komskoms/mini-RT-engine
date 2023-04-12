/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 02:25:44 by jihokim           #+#    #+#             */
/*   Updated: 2021/04/15 00:42:18 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			render_frame(t_vars *v_)
{
	char		count[9];

	if (!v_->r_info.count++)
		printf("Rendering has just begun\n");
	rt_render(v_, &v_->r_info);
	mlx_put_image_to_window(v_->mlx, v_->win, v_->img.inst, 0, 0);
	if (v_->flag[0])
	{
		my_itoa8(count, v_->r_info.count);
		mlx_string_put(v_->mlx, v_->win, 100, 100, 0x00FFFFFF, count);
	}
	return (0);
}

void		save_scene_bmp(t_vars *v_, int count)
{
	printf("Saving as BMP : Rendering the scene...\n");
	printf("(Rendering rate : %d times per a pixel)\n", count);
	while (v_->r_info.count++ < count)
	{
		rt_render(v_, &v_->r_info);
		printf("%d ", v_->r_info.count);
	}
	printf("\n");
	save_bmp(v_, "minirt.bmp");
	cam_list_clear(v_->cam);
	object_list_clear(v_->obj);
	mlx_destroy_image(v_->mlx, v_->img.inst);
	exit_with_msg("finished\n", 0);
}

static int	param_error_handle(int argc, char **argv)
{
	int		len;

	if (argc > 3)
		return (exit_with_msg("too many arguments\n", 1));
	if (argc == 3)
	{
		len = ft_strlen(argv[2]);
		if (ft_strncmp(argv[2], "--save", (len > 6 ? len : 6)))
			return (exit_with_msg("unknown option\n", 1));
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_vars		v_;

	if (param_error_handle(argc, argv))
		return (0);
	v_.mlx = mlx_init();
	v_.obj = 0;
	v_.cam = 0;
	if (!scene_prepare(argc, argv, &v_))
		return (exit_with_msg("failed with scene generation\n", 0));
	if (argc == 3)
		save_scene_bmp(&v_, BMP_RENDERING_RATE);
	else
	{
		mlx_hook(v_.win, 17, 1L << 17, terminate_minirt, &v_);
		mlx_key_hook(v_.win, key_hook, &v_);
		mlx_loop_hook(v_.mlx, render_frame, &v_);
		mlx_loop(v_.mlx);
	}
	return (0);
}
