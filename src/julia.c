/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:33:06 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/27 18:09:47 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int iterate_julia(t_data *data)
{
           data->re = (data->i - WIN_SIZE / 2.0) * data->zoom / WIN_SIZE
				+ data->x;
			data->im = (data->j - WIN_SIZE / 2.0) * data->zoom / WIN_SIZE
				+ data->y ;
            
    while (data->n < 100 && data->re * data->re + data->im * data->im < 4)
    {
       data->temp = data->re;
        data->re = data->re * data->re - data->im * data->im + data->cons_re;
        data->im = 2 * data->temp * data->im + data->cons_im;
    data->n++;
    }
    return (data->n);
}
void julia(t_data *data)
{
    data->j = 0;
    while (data->j < WIN_SIZE)
    {
        data->i = 0;
        while (data->i < WIN_SIZE)
        {
            data->n = 0;
            my_putpixel(data, data->i, data->j, iterate_julia(data) *  0x000f0f / 100);
            data->i++;
        }
        data->j++;
    }
}
