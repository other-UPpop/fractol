/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:05:02 by rohta             #+#    #+#             */
/*   Updated: 2025/04/20 21:23:01 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_loop(t_comp c, t_fractol f)
{
	t_comp	z;
	int		iter;
	double	temp;

	z.re = 0;
	z.im = 0;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < f.max_iter)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * temp * z.im + c.im;
		iter++;
	}
	return (iter);
}

int	julia_loop(t_comp z, t_fractol f)
{
	int		iter;
	double	temp;

	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < f.max_iter)
	{
		temp = z.re;
		z.re = z.re * z.re - z.im * z.im + f.julia_c.re;
		z.im = 2 * temp * z.im + f.julia_c.im;
		iter++;
	}
	return (iter);
}
