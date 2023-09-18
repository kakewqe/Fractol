/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:29:34 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/18 22:59:24 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	iterate_mandelbrot(t_data *data)
{
	data->c_re = (data->i - WIN_SIZE / 2.0) * data->zoom / WIN_SIZE + data->x;
	data->c_im = (data->j - WIN_SIZE / 2.0) * data->zoom / WIN_SIZE + data->y;
	while (data->n < 100 && data->re * data->re + data->im * data->im < 4)
	{
		data->temp = data->re * data->re - data->im * data->im + data->c_re;
		data->im = 2 * data->re * data->im + data->c_im;
		data->re = data->temp;
		data->n++;
	}
	return (data->n);
}

void	mandelbrot(t_data *data)
{
	data->i = 0;
	while (data->i < WIN_SIZE)
	{
		data->j = 0;
		while (data->j < WIN_SIZE)
		{
			data->n = 0;
			data->re = 0;
			data->im = 0;
			if (data->n < 100)
				my_putpixel(data, data->i, data->j,
					iterate_mandelbrot(data) * 0x000f0f / 100);
			data->j++;
		}
		data->i++;
	}
}