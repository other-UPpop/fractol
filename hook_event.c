/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:50:29 by rohta             #+#    #+#             */
/*   Updated: 2025/04/21 23:23:12 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	redraw_fractol(t_fractol *f)
{
	mlx_clear_window(f->mlx, f->win);
	if (f->img.img_ptr != NULL)
	{
		mlx_destroy_image(f->mlx, f->img.img_ptr);
	}
	draw_fractol(f);
}

static int	mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	static double	zoom;

	if (zoom == 0)
		f->view.zoom = 1.0;
	if (mousecode == SCROLL_UP)
		f->view.zoom *= 1.1;
	else if (mousecode == SCROLL_DOWN)
		f->view.zoom *= 0.9;
	redraw_fractal(f);
	return (0);
}

static int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(f->mlx, f->img.img_ptr);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	return (0);
}

void	do_event(t_fractol *f)
{
	mlx_mouse_hook(f->win, &mouse_hook, f);
	mlx_key_hook(f->win, &key_hook, f);
}
