/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oclerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 12:19:47 by ggregoir          #+#    #+#             */
/*   Updated: 2017/12/10 12:47:38 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		print_cl_infos(cl_context context)
{
	cl_device_id		devices[MAX_DEVICE];
	size_t				size;
	int					elements;
	cl_int				err;
	int					i;
	int					speed;
	char				vendor_name[1024];
	char				device_name[1024];

	i = 0;
	err = clGetContextInfo(context, CL_CONTEXT_DEVICES, sizeof(cl_device_id) * 16,
		&devices, &size);
	get_cl_error("Getting context info", err);
	elements = size / sizeof(cl_device_id);
	while (i < elements)
	{
		err = clGetDeviceInfo(devices[i], CL_DEVICE_VENDOR,
			sizeof(vendor_name), (void *)vendor_name, NULL);
		err |= clGetDeviceInfo(devices[i], CL_DEVICE_NAME,
			sizeof(device_name), (void *)device_name, NULL);
		err |= clGetDeviceInfo(devices[i], CL_DEVICE_MAX_CLOCK_FREQUENCY,
			sizeof(speed), &speed, NULL);
		get_cl_error("Getting device info", err);
		printf("Loaded: %s %s %dmHz\n", vendor_name, device_name, speed);
		i++;
	}
}

const char	*g_cl_errors[] = {
	"Device not found",
	"Device not available",
	"Compiler not available",
	"Memory object allocation failure",
	"Out of resources",
	"Out of host memory",
	"Profiling info not available",
	"Memory copy overlap",
	"Image format mismatch",
	"Image format not supported",
	"Build program failure",
	"Map failure",
	"Invalid value",
	"Invaid device type",
	"Invalid platform",
	"Invalid device",
	"Invalid context",
	"Invalid queue properties",
	"Invalid command queue",
	"Invalid host pointer",
	"Invalid memory object",
	"Invalid image format descriptor",
	"Invalid image size",
	"Invalid sampler",
	"Invalid binary",
	"Invalid build options",
	"Invalid program",
	"Invalid program executable",
	"Invalid kernel name",
	"Invalid kernel defintion",
	"Invalid kernel",
	"Invalid argument index",
	"Invalid argument value",
	"Invalid argument size",
	"Invalid kernel arguments",
	"Invalid work dimension",
	"Invalid work group size",
	"Invalid work item size",
	"Invalid global offset",
	"Invalid event wait list",
	"Invalid event",
	"Invalid operation",
	"Invalid GL object",
	"Invalid buffer size",
	"Invalid mip level",
	"Invalid global work size"
};

void		get_cl_error(char *debug, cl_int err)
{
	ft_putstr_fd(debug, 2);
	ft_putstr_fd("\033[31m:\t", 2);
	ft_putstr_fd(g_cl_errors[-err -1], 2);
    ft_putstr_fd("\033[0m", 2);
    if (err)
    	exit(EXIT_FAILURE);
    else
    	ft_putstr_fd("\033[32mOK!\033[0m\n", 2);
}