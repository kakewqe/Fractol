/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:44:29 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/22 23:31:21 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	error_fractals(char **av)
{
	if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "julia.1")
		|| !ft_strcmp(av[1], "julia.2")
		|| !ft_strcmp(av[1], "mandelbrot"))
		return (0);
	return (1);
}

void	ft_error(void)
{
	write(1, "---------------------------\n", 28);
	write(1, "     mandelbrot\n", 17);
	write(1, "     julia\n", 12);
	write(1, "    julia.1\n", 13);
	write(1, "    julia.2\n", 13);
	write(1, "----------------------------", 27);
	exit(EXIT_FAILURE);
}

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->ptr, data->img);
	mlx_destroy_window(data->ptr, data->win);
	mlx_loop_end(data->ptr);
	exit(EXIT_FAILURE);
}
