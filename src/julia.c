/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:33:06 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/23 06:25:04 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	iterate_julia(char *av, t_data *data)
{
	if (!ft_strcmp(av, "julia.1"))
	{
		data->cons_re = -0.7017;
		data->cons_im = -0.3842;
	}
	else if (!ft_strcmp(av, "julia.2"))
	{
		data->cons_re = -0.3842;
		data->cons_im = -0.7017;
	}
	else
	{
		data->cons_re = 0.3954;
		data->cons_im = 0.3945;
	}
	while (data->n < 100 && data->re * data->re + data->im * data->im < 4)
	{
		data->temp = data->re * data->re - data->im * data->im;
		data->im = 2 * data->re * data->im + data->cons_re;
		data->re = data->temp + data->cons_im;
		data->n++;
	}
	return (data->n);
}

void	julia(char *av, t_data *data)
{
	// static int h = 0;
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
				my_putpixel(data, data->i, data->j, iterate_julia(av, data)
					* 0x000f0f * 100);
			data->j++;
		}
		data->i++;
	}
}

// si iter > 100 ||iter  < 4 NOIR
// apres autre couleurs a test