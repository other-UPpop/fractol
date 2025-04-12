/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:53:24 by rohta             #+#    #+#             */
/*   Updated: 2025/04/12 17:48:49 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_complex
{
	double	re;
	double	im;
}	t_comp;

typedef struct s_view
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}	t_view;

typedef struct s_image
{
	void	*img_ptr;
	char	*data;
	int		ppp; //bit per pixel
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	char	*type;
	int		width;
	int		height;
	int		mouse;
	int		color;
	t_image	image;
	t_view	view;
	t_comp	julia_c;
}	t_fractol;


# endif

