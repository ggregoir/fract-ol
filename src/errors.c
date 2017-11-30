/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:25:06 by ggregoir          #+#    #+#             */
/*   Updated: 2017/11/14 14:16:03 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol_exit(void)
{
	exit(1);
}

void	malloc_error(void)
{
	ft_putstr_fd("malloc error\n", 2);
	fractol_exit();
}

void	map_error(void)
{
	ft_putstr_fd("map error\n", 2);
	fractol_exit();
}

void	usage_error(void)
{
	ft_putstr_fd("usage: ./fractol [X][Y][ensemble]\n", 2);
	fractol_exit();
}

void	arg_error(void)
{
	ft_putstr_fd("Un seul argument pris en compte.\n", 2);
	fractol_exit();
}
