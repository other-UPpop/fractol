/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:17:20 by rohta             #+#    #+#             */
/*   Updated: 2025/05/08 13:39:12 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	arg_check(int ac, char **av)
{
	if (ac < 2 || ac > 4 || ac == 3)
		return (error_print(2), 1);
	if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
	{
		if (ac > 2)
			return (error_print(3), 1);
		return (0);
	}
	if (ft_strncmp(av[1], "Julia", 6) == 0)
	{
		if (ac < 4)
			return (error_print(3), 1);
		return (0);
	}
	return (1);
}
