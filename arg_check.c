/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:17:20 by rohta             #+#    #+#             */
/*   Updated: 2025/05/06 14:49:36 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_arg_check(int argc, char **argv, t_fractol *f)
{
	if (argc < 4)
	{
		error_print(3);
		exit (1);
	}
	printf("julia\n");
	init_julia(f, argv);
	return (0);
}
