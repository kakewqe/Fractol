/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:07:12 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/20 12:07:16 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	my_putpixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
}

int	mouse_and_esc(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		exit(EXIT_FAILURE);
	mlx_clear_window(data->ptr, data->win);
	if (!ft_strcmp(data->fractal, "julia")
		|| !ft_strcmp(data->fractal, "julia.1")
		|| !ft_strcmp(data->fractal, "julia.2"))
		julia(data->fractal, data);
	if (!ft_strcmp(data->fractal, "mandelbrot"))
		mandelbrot(data);
	return (0);
}

int	zoom(int keycode, int x, int y, t_data *data)
{
	double	zoom_factor;
	double	dx;
	double	dy;

	zoom_factor = 0.5;
	if (keycode == MOUSE_DOWN || keycode == MOUSE_UP)
	{
		if (keycode == MOUSE_DOWN)
			data->zoom /= zoom_factor;
		else
			data->zoom *= zoom_factor;
		dx = x - WIN_SIZE / 2.0;
		dy = y - WIN_SIZE / 2.0;
		data->x += dx * data->zoom / WIN_SIZE;
		data->y += dy * data->zoom / WIN_SIZE;
	}
	mlx_clear_window(data->ptr, data->win);
	if (!ft_strcmp(data->fractal, "julia")
		|| !ft_strcmp(data->fractal, "julia.1")
		|| !ft_strcmp(data->fractal, "julia.2"))
		julia(data->fractal, data);
	if (!ft_strcmp(data->fractal, "mandelbrot"))
		mandelbrot(data);
	mlx_put_image_to_window(data->ptr, data->win, data->img, 0, 0);
	return (0);
}
