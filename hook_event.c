/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:50:29 by rohta             #+#    #+#             */
/*   Updated: 2025/05/05 19:32:04 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_view_zoom(t_fractol *f, int x, int y, double factor)
{
	double	center_re;
	double	center_im;
	double	new_width;
	double	new_height;

	(void)x;
	(void)y;
	center_re = (f->view.min_re + f->view.max_re) / 2.0;
	center_im = (f->view.min_im + f->view.max_im) / 2.0;
	new_width = (f->view.max_re - f->view.min_re) * factor;
	new_height = (f->view.max_im - f->view.min_im) * factor;
	f->view.min_re = center_re - new_width / 2;
	f->view.max_re = center_re + new_width / 2;
	f->view.min_im = center_im - new_height / 2;
	f->view.max_im = center_im + new_height / 2;
	f->need_draw = true;
}

void	redraw_fractol(t_fractol *f)
{
	if (f->need_draw == true)
	{
		draw_fractol(f);
		mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
		f->need_draw = false;
	}
}

int	mouse_hook(int code, int x, int y, void *param)
{
	t_fractol	*f;

	(void)x;
	(void)y;
	f = (t_fractol *)param;
	if (code == SCROLL_UP)
		update_view_zoom(f, x, y, 0.9);
	else if (code == SCROLL_DOWN)
		update_view_zoom(f, x, y, 1.1);
	redraw_fractol(f);
	return (0);
}


int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(f->mlx, f->img.img_ptr);
		mlx_destroy_window(f->mlx, f->win);
		if (f->mlx)
			free(f->mlx);
	}
	return (0);
}

int	close_window(t_fractol *f)
{
	if (f->img.img_ptr)
		mlx_destroy_image(f->mlx, f->img.img_ptr);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
		free(f->mlx);
	return (0);
}

void	do_event(t_fractol *f)
{
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_key_hook(f->win, &key_hook, f);
	mlx_hook(f->win, 17, 0, &close_window, f);
}
