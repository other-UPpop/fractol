/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:53:24 by rohta             #+#    #+#             */
/*   Updated: 2025/05/06 13:42:27 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MANDELBROT "MANDELBROT"
# define JULIA "JULIA"
# define WIDTH 400
# define HEIGHT 400
# define ESC 65307
# define SCROLL_UP 5
# define SCROLL_DOWN 4

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
	double	zoom;
	double	resolution_scale;
}	t_view;

typedef struct s_image
{
	void	*img_ptr;
	char	*data;
	int		bpp; 
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	char	*type;
	bool	need_draw;
	int		width;
	int		height;
	int		mouse;
	int		color;
	int		max_iter;
	t_image	img;
	t_view	view;
	t_comp	julia_c;
}	t_fractol;

int		main(int argc, char **argv);
void	draw_fractol(t_fractol *f);

void	init_graphics(t_fractol *f);
void	init_mandelbrot(t_fractol *f);
void	init_julia(t_fractol *f, char **argv);

int		julia_arg_check(int argc, char **argv, t_fractol *f);

t_comp	pixel_complex(int x, int y, t_view view);
int		loop_calculate(t_comp c, t_fractol f);
int		get_color(int iter, int max_iter);
void	put_pixel(t_image img, int x, int y, int color);

int		mandelbrot_loop(t_comp c, t_fractol f);
int		julia_loop(t_comp z, t_fractol f);

void	do_event(t_fractol *f);
void	redraw_fractol(t_fractol *f);

double	ft_atof(char *str);
void	error_print(int n);

#endif