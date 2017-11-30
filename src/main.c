/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:30:36 by ggregoir          #+#    #+#             */
/*   Updated: 2017/11/30 17:12:05 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>
#include <limits.h>

void	put_pixel(t_e *e, int x, int y, int color)
{
	e->data[(x * (e->bpp / 32 )) + (y * (e->sizeline / 4) ) ] = color;
}

void	ft_black_screen(t_e *e)
{
	int x;
	int y;

	y = 0;
	while (y != e->w_y)
	{
		x = 0;
		while (x != e->w_x)
		{
			put_pixel(e, x, y, XBLACK);
			x++;
		}
		y++;
	}
}

void	fractal(t_e *e)
{
	t_complex a;
	double x;
	double y;
	double xnew;
	x = 0;
	y = 0;
	int iter;
	int row;
	int col;
	row = 0;
	col = 0;

	x = 0;
	y = 0;
	
	while (row < e->w_y)
	{
		col = 0;
		while (col < e->w_x)
		{
			a = complex((col - e->w_x/e->posx) * 4.0 / e->zoomx, (row - e->w_y/e->posy) * 4.0 / e->zoomy);
			iter = 0;
			x = 0;
			y = 0;
			//printf("col = %d row = %d x = %f, y = %f a->i = %f a->r = %f\n",col, row, x, y, a.i, a.r);
			while(x * x + y * y <= 4 && iter < e->iter)
			{
				//printf("in col = %d row = %d x = %f, y = %f a->i = %f a->r = %f\n",col, row, x, y, a.i, a.r);
				xnew = x*x - y*y + a.r;
				y = 2*x*y + a.i;
				x = xnew;
				iter++;
				//printf("after iter col = %d row = %d x = %f, y = %f a->i = %f a->r = %f\n",col, row, x, y, a.i, a.r);
			}
			//printf("iter = %d\n", iter);
			if (iter < e->iter)
			{
				int color = (XBLACK + iter) * 10;
				put_pixel(e, col, row , color);
			}
			col++;
		}
		row++;
	}

}

/*t_complex	adapt_screen(int x, int y, t_e *e)
{

}
*/
/*
t_complex	mul_com(t_complex a, t_complex b)
{
	t_complex res;

	res->r = (a->r * b->r) - (a->i * b->i);
	res->i = (a->r * b->i) + (a->i * b->r);
	return (res);
}

t_complex	add_com(t_complex a, t_complex b)
{
	t_complex res;

	res->r = a->r + b->r;
	res->i = a->i + b->i;
	return (res);
}
*/

int		key_hook(int keycode, t_e *e)
{
	if (!e)
		fractol_exit();
	
	if (keycode == 13)
	{
		if (e->posy > 0)
			e->posy = e->posy - 0.02;
		ft_black_screen(e);
		fractal(e);
		mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	}

	if (keycode == 1)
	{
		if (e->posy < 4)
			e->posy = e->posy + 0.02;
		ft_black_screen(e);
		fractal(e);
		mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	}

	if (keycode == 0)
	{
		if (e->posx > 0)
			e->posx = e->posx - 0.02;
		ft_black_screen(e);
		fractal(e);
		mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	}

	if (keycode == 2)
	{
		if (e->posx < 4)
			e->posx = e->posx + 0.02;
		ft_black_screen(e);
		fractal(e);
		mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	}

	if (keycode == 53)
	{
		exit(0);
	}

	if (keycode == 14)
	{
		if (e->zoomx + e->zoomx / 10 > 0 && e->zoomy + e->zoomy / 10 > 0)
		{
			e->zoomx = e->zoomx + e->zoomx / 10;
			e->zoomy = e->zoomy + e->zoomy / 10;
		}
		ft_black_screen(e);
		fractal(e);
		mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	}

	if (keycode == 15)
	{
		if (e->zoomx - e->zoomx / 10 > 0 && e->zoomy - e->zoomy / 10 > 0)
		{
			e->zoomx = e->zoomx - e->zoomx / 10;
			e->zoomy = e->zoomy - e->zoomy / 10;
		}
		ft_black_screen(e);
		fractal(e);
		mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	}

	if (keycode == 43)
	{
		printf("e->iter = %d\n", e->iter);
		if (e->iter >= 1)
			e->iter = e->iter - 1;
		ft_black_screen(e);
		fractal(e);
		mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	}

	if (keycode == 47)
	{
		printf("e->iter = %d\n", e->iter);
		if (e->iter <= 5000)
			e->iter = e->iter + 1;
		fractal(e);
		mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	}



	return (0);
}
void	env_init(t_e *e, char **argv, int argc)
{
	int i;
	int j;

	e->iter = 1;
	e->posx = 2.0;
	e->posy = 2.0;
	if (argc == 2)
	{
		e->w_x = 1000;
		e->w_y = 1000;
		return;
	}
	i = 0;
	j = 1;
	while (argv[1][i])
	{
		if(ft_isdigit(argv[1][i]) == 0)
			usage_error();
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		if(ft_isdigit(argv[2][i]) == 0)
			usage_error();
		i++;
	}
	e->w_x = ft_atoi(argv[1]);
	e->w_y = ft_atoi(argv[2]);
}

int		main(int argc, char **argv)
{
	t_e		e;
	
	if (argc >= 2)
	{
		env_init(&e, argv, argc);
		e.zoomx = e.w_x;
		e.zoomy = e.w_y;
		if ((e.mlx_ptr = mlx_init()) == NULL)
			return (EXIT_FAILURE);
		if ((e.mlx_win =
			mlx_new_window(e.mlx_ptr, e.w_x, e.w_y, "Fract'ol")) == NULL)
			return (EXIT_FAILURE);
		if ((e.img_ptr = mlx_new_image(e.mlx_ptr, e.w_x, e.w_y)) == NULL)
			return (EXIT_FAILURE);
		e.data = (int*)mlx_get_data_addr(e.img_ptr, &e.bpp, &e.sizeline, &e.endian);
		ft_putstr(argv[1]);
		fractal(&e);
		mlx_put_image_to_window(e.mlx_ptr, e.mlx_win, e.img_ptr, 0, 0);
		mlx_hook(e.mlx_win, 2, 0, key_hook, &e);
		mlx_loop(e.mlx_ptr);
	}
	else
	{
		ft_putstr("usage: ./fractol [X][Y][ensemble]\n");
	}
	return (0);
}
