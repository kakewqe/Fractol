/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:33:06 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/20 09:42:00 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	iterate_julia(char *av, t_data *data)
{
	if (!ft_strcmp(av, "julia.1"))
	{
		data->c_re = -0.56667;
		data->c_im = -.5;
	}
	else if (!ft_strcmp(av, "julia.2"))
	{
		data->c_re = -0.74543;
		data->c_im = 0.11301;
	}
	else
	{
		data->c_re = -0.7;
    	data->c_im = 0.27015;
	}
	while (data->n < 100 && data->re * data->re + data->im * data->im < 4)
	{
		data->temp = data->re * data->re - data->im * data->im;
		data->im = 2 * data->re * data->im + data->c_re;
		data->re = data->temp + data->c_im;
		data->n++;
	}
	return (data->n);
}

void	julia(char *av, t_data *data)
{
	data->i = 0;
	while (data->i < WIN_SIZE)
	{
		data->j = 0;
		while (data->j < WIN_SIZE)
		{
			data->n = 0;
			data->re = (data->i - WIN_SIZE / 2) * (data->zoom / WIN_SIZE)
				+ data->x;
			data->im = (data->j - WIN_SIZE / 2) * (data->zoom / WIN_SIZE)
				+ data->y;
			if (data->n < 100)
				my_putpixel(data, data->i, data->j,
					iterate_julia(av, data) * 0x000f0f / 100);
			data->j++;
		}
		data->i++;
	}
}
