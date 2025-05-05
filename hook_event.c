/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:50:29 by rohta             #+#    #+#             */
/*   Updated: 2025/05/05 17:13:13 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw_fractol(t_fractol *f)
{
//	mlx_clear_window(f->mlx, f->win);
//	if (f->img.img_ptr != NULL)
//	{
//		//mlx_destroy_image(f->mlx, f->img.img_ptr);
	//	printf("doing\n");
//	}
//	f->img.img_ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
//	f->img.data = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
//			&f->img.size_line, &f->img.endian);
	draw_fractol(f);
}

int	mouse_hook(int mousecode, int x, int y, void *param)
{
	t_fractol	*f;

	(void)x;
	(void)y;
	f = (t_fractol *)param;
	if (f->view.zoom <= 0.0)
		f->view.zoom = 1.0;

	if (mousecode == SCROLL_UP)
		f->view.zoom *= 1.025;
	else if (mousecode == SCROLL_DOWN)
		f->view.zoom *= 0.975;
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
