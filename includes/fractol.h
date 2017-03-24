/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:42:52 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/24 17:06:27 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "..//libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# define BPP e->bpp
# define SL e->sizeline
# define EN e->endian
# define DATA e->data
# define W_X e->w_x
# define W_Y e->w_y
# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define GREY 0x777777
# define WHITE 0xffffff
# define YELLOW 0x00ffff
# define CYAN 0xffff00
# define MAGENTA 0xff00ff
# define SILVER 0xC0C0C0
# define DEEPBLUE 0x000080
# define LIME 0x00FF00
# define BROWN 0x800000
# define BLACK 0x000000
# define TEAL 0x008080
# define LIGHTGREEN 0x008000
# define OLIVEGREEN 0x808000
# define PURPLE 0x800080



typedef struct	e_s
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			w_x;
	int			w_y;

}				e_t;

#endif