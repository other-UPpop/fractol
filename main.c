/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:43:07 by rohta             #+#    #+#             */
/*   Updated: 2025/05/06 16:50:45 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_event(t_fractol *f)
{
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_key_hook(f->win, &key_hook, f);
	mlx_hook(f->win, 17, 0, &close_window, f);
}

void	draw_fractol(t_fractol *f)
{
	int		x;
	int		y;
	int		iter;	
	int		step;
	t_comp	c;

	step = (int)(1.0 / f->view.resolution_scale);
	if (step < 1)
		step = 1;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = pixel_complex(x, y, f->view);
			iter = loop_calculate(c, *f);
			put_pixel(f->img, x, y, get_color(iter, f->max_iter));
			x += step;
		}
		y += step;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2)
		return (error_print(1), 1);
	init_fractol(&f);
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		init_mandelbrot(&f);
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
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
