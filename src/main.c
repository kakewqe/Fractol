/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:14:22 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/27 18:19:12 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

//ft_bezzero
void	init(t_data *data)
{
	data->ptr = NULL;
	data->win = NULL;
	data->img = NULL;
	data->x = 0;
	data->y = 0;
	data->re = 0;
	data->im = 0;
	data->temp = 0;
	data->cons_re = 0;
	data->cons_im = 0;
	data->addr = NULL;
	data->fractal = 0;
	data->j = 0;
	data->n = 0;
	data->i = 0;
	data->endian = 0;
	data->line_length = 0;
	data->bits_per_pixel = 0;
    data->min_r = 0;
	data->max_r = 0;
	data->min_i = 0;
	data->max_i = 0; 
}

void	hooks(t_data *data)
{
	mlx_key_hook(data->win, mouse_and_esc, data);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_mouse_hook(data->win, zoom, data);
}

void	create_window_image(t_data *data)
{
	data->ptr = mlx_init();
	if (!data->ptr)
		exit(1);
	data->win = mlx_new_window(data->ptr, WIN_SIZE, WIN_SIZE, "Fractal");
	if (!data->win)
		exit(1);
	data->img = mlx_new_image(data->ptr, WIN_SIZE, WIN_SIZE);
	if (!data->img)
		exit(1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void fractale(char **av, int ac, t_data *data)
{
    if (!ft_strcmp(av[1], "julia"))
    {
        if (ac == 4)
        {
            data->cons_re = ft_atof(av[2]);
            data->cons_im = ft_atof(av[3]);
        }
        else if (ac == 2)
        {
            data->cons_re =  0.285 ; 
            data->cons_im = 0.013;
        }
        else if (ac >= 5 || ac == 3)
        {
            ft_error();
            ft_close(data);
        }
        julia(data);
        data->fractal = ft_strdup(av[1]);
    }
    else if (!ft_strcmp(av[1], "mandelbrot"))
    {
        if (ac != 2)
        {
            ft_error();
            ft_close(data);
        }  
        else 
        {
             mandelbrot(data);
            data->fractal = ft_strdup(av[1]);
        }
    }
    mlx_put_image_to_window(data->ptr, data->win, data->img, 0, 0);
}

int main(int ac, char **av)
{
    t_data data;

    if (ac < 2  || error_fractals(av))
    {
        ft_error();
        return (-1);
    }
    init(&data);
    data.zoom = -2.0;
    create_window_image(&data);
    fractale(av, ac, &data); 
    hooks(&data);
    mlx_loop(data.ptr);
    ft_close(&data);
    return (0);
}