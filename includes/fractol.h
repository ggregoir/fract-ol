/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:42:52 by ggregoir          #+#    #+#             */
/*   Updated: 2017/11/30 16:49:56 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "..//libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

# define XRED 0xFF0000
# define XBLUE 0x0000FF
# define XGREEN 0x00FF00
# define XGREY 0x777777
# define XWHITE 0xffffff
# define XYELLOW 0x00ffff
# define XCYAN 0xffff00
# define XMAGENTA 0xff00ff
# define XSILVER 0xC0C0C0
# define XDEEPBLUE 0x000080
# define XLIME 0x00FF00
# define XBROWN 0x800000
# define XBLACK 0x000000
# define XTEAL 0x008080
# define XLIGHTGREEN 0x008000
# define XOLIVEGREEN 0x808000
# define XPURPLE 0x800080

typedef struct	s_complex
{
	double		r;
	double		i;

}				t_complex;

typedef struct	s_e
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
	int			zoomx;
	int			zoomy;
	int			iter;
	double 		posx;
	double		posy;
}				t_e;

void		fractol_exit(void);
void		malloc_error(void);
void		map_error(void);
void		usage_error(void);
void		arg_error(void);
t_complex	complex(double i, double r);


#endif
