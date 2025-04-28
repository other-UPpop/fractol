/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:21:00 by rohta             #+#    #+#             */
/*   Updated: 2025/04/28 15:18:20 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_issign(char **str)
{
	int		sign;
	size_t	i;

	sign = 0;
	i = 0;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign++;
		i++;
		(*str)++;
	}
	if (i > 1)
		return (0);
	if (sign)
		return (-1);
	return (1);
}

double	ft_atof(char *str)
{
	double	number;
	int		sign;
	int		i;
	double	n;

	sign = 1;
	number = 0;
	n = 0.1;
	i = 0;
	if (!str)
		return (0.0);
	sign *= ft_issign(&str);
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number + (str[i++] - '0') * n;
		n *= 0.1;
	}
	return (number * sign);
}
