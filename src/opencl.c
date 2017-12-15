/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 11:48:46 by ggregoir          #+#    #+#             */
/*   Updated: 2017/12/10 20:10:06 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

cl_context	create_context(cl_uint *num_devices)
{
	cl_int			err;
	cl_device_id	*devices;
	cl_device_id	cpus[MAX_DEVICE];
	cl_uint			num_cpus;
	cl_context		context;

	devices = malloc(16 * sizeof(cl_device_id));
	err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_CPU, MAX_DEVICE, cpus, &num_cpus);
	get_cl_error("Getting Cpu(s) IDs", err);
	err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, MAX_DEVICE,
		devices, num_devices);
	get_cl_error("Getting Gpu(s) IDs", err);
	if (err != CL_SUCCESS || *num_devices == 0)
	{
		devices = cpus;
		*num_devices = num_cpus;
	}
	if (devices == 0)
		get_cl_error("OpenCL: No suitable hardware found", err);
	context = clCreateContext(0, *num_devices, devices, NULL, NULL, &err);
	get_cl_error("Creating context", err);
	return (context);
}

int		opencl(t_e *e)
{
	t_opencl 	ocl;
	size_t		buffer_size;
	int 		*host_image;
	cl_uint 	i;

	ft_bzero(&ocl, sizeof(t_opencl));
	ocl.width = e->w_x;
	ocl.height = e->w_y;
	buffer_size = sizeof(int) * ocl.width * ocl.height;
	host_image = (int *)ft_memalloc(buffer_size);
	ocl.context = create_context(&ocl.num_devices);
	if(ocl.num_devices == 0)
	{
		ft_putendl("OpenCL: No compute devices found\n");
		exit (EXIT_FAILURE);
	}
	print_cl_infos(ocl.context);
	ocl.err = clGetContextInfo(ocl.context, CL_CONTEXT_DEVICES,
		sizeof(cl_device_id) * 16, &ocl.devices, NULL);
	get_cl_error("Getting context info", ocl.err);
	i = -1;
	while(++i < ocl.num_devices)
	{
		ocl.cmd_queue[i] = clCreateCommandQueue(ocl.context, ocl.devices[i], 0, &ocl.err);
		get_cl_error("Creating command queue", ocl.err);
	}


	return(1);

}