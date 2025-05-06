/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:43:07 by rohta             #+#    #+#             */
/*   Updated: 2025/05/06 14:07:36 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_fractol *f)
{
	int		x;
	int		y;
	int		iter;	
	int		color;
	t_comp	c;
	int		step_x;
	int		step_y;

	step_x = (int)(1.0 / f->view.resolution_scale);
	step_y = (int)(1.0 / f->view.resolution_scale);
	if (step_x < 1)
		step_x = 1;
	if (step_y < 1)
		step_y = 1;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = pixel_complex(x, y, f->view);
			iter = loop_calculate(c, *f);
			color = get_color(iter, f->max_iter);
			put_pixel(f->img, x, y, color);
			x += step_x;
		}
		y += step_y;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2)
		return (error_print(1), 1);
	init_graphics(&f);
	if (!strcmp(argv[1], "Mandelbrot"))
		init_mandelbrot(&f);
	else if (!strcmp(argv[1], "Julia"))
	{
		if (julia_arg_check(argc, argv, &f) == 1)
			return (1);
	}
	else
		return (error_print(2), 1);
	draw_fractol(&f);
	do_event(&f);
	mlx_loop(f.mlx);
	return (0);
}
