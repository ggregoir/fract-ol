/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 13:17:09 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/24 17:15:49 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook(int keycode, e_t e)
{
	if (!e.mlx_ptr)
		e.mlx_ptr = 0;
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}
void	env_init(e_t *e)
{
	W_X = 2000;
	W_Y = 1200;
}


void	put_pixel(e_t *e, int x, int y, int color)
{
	DATA[(x * (BPP / 16 ))  + (y * (SL / 2) ) ] = color;
}
int		main(int argc, char **argv)
{
	e_t		e;
	
	if (argc == 2)
	{
		env_init(&e);
		if ((e.mlx_ptr = mlx_init()) == NULL)
			return (EXIT_FAILURE);
		if ((e.mlx_win =
			mlx_new_window(e.mlx_ptr, e.w_x, e.w_y, "Fract'ol")) == NULL)
			return (EXIT_FAILURE);
		if ((e.img_ptr = mlx_new_image(e.mlx_ptr, e.w_x, e.w_y)) == NULL)
			return (EXIT_FAILURE);
		e.data = (int*)mlx_get_data_addr(e.img_ptr, &e.bpp, &e.sizeline, &e.endian);
		ft_putstr(argv[1]);
		put_pixel(&e, 200, 100 , PURPLE);
		mlx_put_image_to_window(e.mlx_ptr, e.mlx_win, e.img_ptr, 0, 0);
		mlx_key_hook(e.mlx_win, key_hook, 0);
		mlx_loop(e.mlx_ptr);
	}
	ft_putstr("usage: ./fractol [ensemble]\n");
	return (0);
}