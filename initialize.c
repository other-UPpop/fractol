/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:21:42 by rohta             #+#    #+#             */
/*   Updated: 2025/05/08 07:53:10 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_graphics(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	f->img.img_ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img.data = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
			&f->img.size_line, &f->img.endian);
}

void	init_fractol(t_fractol *f)
{
	init_graphics(f);
	f->height = HEIGHT;
	f->width = WIDTH;
	ft_memset(f->img.data, 0, f->height * f->img.size_line);
	f->view.resolution_scale = 1.0;
	f->max_iter = 150;
	f->view.zoom = 1.0;
}

void	init_mandelbrot(t_fractol *f)
{
	f->type = "MANDELBROT";
	f->view.min_re = -2.5;
	f->view.max_re = 1.0;
	f->view.min_im = -1.5;
	f->view.max_im = 1.5;
}

void	init_julia(t_fractol *f, char **argv)
{
	f->type = "JULIA";
	f->julia_c.re = ft_atof(argv[2]);
	f->julia_c.im = ft_atof(argv[3]);
	f->view.min_re = -2.0;
	f->view.max_re = 2.0;
	f->view.min_im = -2.0;
	f->view.max_im = 2.0;
}
