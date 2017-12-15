/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:42:52 by ggregoir          #+#    #+#             */
/*   Updated: 2017/12/10 12:49:08 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "..//libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
#include "OpenCL/opencl.h"
#include <stdio.h>

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

# define MAX_DEVICE				16

typedef struct	s_complex
{
	double		r;
	double		i;

}				t_complex;

typedef struct			s_opencl
{
	char				*kernel_source;
	cl_uint				num_devices;
	cl_kernel			kernel;
	cl_command_queue	cmd_queue[16];
	cl_context			context;
	cl_mem				image;
	cl_device_id		devices[16];
	cl_int				err;
	cl_uint				width;
	cl_uint				height;
	size_t				device_work_size[2];
	size_t				device_work_offset[2];
	size_t				offset;
}						t_opencl;

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
int			opencl(t_e *e);
void		get_cl_error(char *debug, cl_int err);
void		print_cl_infos(cl_context context);


#endif
