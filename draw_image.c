/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:28:52 by rohta             #+#    #+#             */
/*   Updated: 2025/04/28 15:28:54 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp	pixel_complex(int x, int y, t_view view)
{
	t_comp	c;
	double	x_re;
	double	y_im;

	x_re = (view.max_re - view.min_re) / view.zoom;
	y_im = (view.max_im - view.min_im) / view.zoom;
	c.re = view.min_re + ((double)x / WIDTH * x_re);
	c.im = view.max_im - ((double)y / HEIGHT * y_im);
	return ((t_comp)c);
}

int	loop_calculate(t_comp c, t_fractol f)
{
	t_comp	z;

	if (ft_strncmp(f.type, MANDELBROT, 10) == 0)
		return (mandelbrot_loop(c, f));
	else if (ft_strncmp(f.type, JULIA, 6) == 0)
	{
		z = c;
		return (julia_loop(z, f));
	}
	return (0);
}

int	get_color(int iter, int max_iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == max_iter)
		return (0x000000);
	r = (iter * 5) % 256;
	g = (iter * 15) % 256;
	b = (iter * 25) % 256;
	return (r << 16 | g << 8 | b);
}

void	put_pixel(t_image img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img.data + (y * img.size_line + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}
