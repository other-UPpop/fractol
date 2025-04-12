/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:43:07 by rohta             #+#    #+#             */
/*   Updated: 2025/04/12 17:56:28 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(void)
{
	t_fractol	frct;
	
}

void	ft_error_tex(int a)
{
	if (a == 0)
	{
		printf("MandelbrotかJuliaと入力してください\n");
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		return (0);
		errror_print();
	}
	if (!strcmp(argv[1], "Mandelbrot"))
		ft_mandelbrot();
	else if (!strcmp(argv[1], "Julia"))
		ft_julia();
	else
		ft_error_tex(0);
	return (0);
}