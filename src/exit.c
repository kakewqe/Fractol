/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:44:29 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/26 18:49:14 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	error_fractals(char **av)
{
	if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "mandelbrot"))
		return (0);
	return (1);
}

void	ft_error(void)
{
	write(1, "---------------------------\n", 28);
	write(1, "Use ./fractol :\n", 16);
	write(1, "     mandelbrot\n", 17);
	write(1, "     julia [] []\n", 18);
	write(1, "----------------------------", 27);
}

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->ptr, data->img);
	mlx_destroy_window(data->ptr, data->win);
	mlx_loop_end(data->ptr);
	mlx_destroy_display(data->ptr);
	free(data->ptr);
	free(data->fractal);
	exit(0);
}
