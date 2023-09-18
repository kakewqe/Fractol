/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:14:22 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/18 23:00:29 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	hooks(t_data *data)
{
	mlx_key_hook(data->win, arrow_move, data);
	mlx_hook(data->win, 17, 0, exit_when_close, data);
	mlx_mouse_hook(data->win, zoom, data);
	mlx_mouse_hook(data->win, zoom, data);
}

void	create_window(t_data *data)
{
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, WIN_SIZE, WIN_SIZE, "Fractal");
}

void	create_image(t_data *data)
{
	data->img = mlx_new_image(data->ptr, WIN_SIZE, WIN_SIZE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	fractale(char *av, t_data *data)
{
	if (!ft_strcmp(av, "julia") || !ft_strcmp(av, "julia.1")
		|| !ft_strcmp(av, "julia.2"))
	{
		julia(av, data);
		data->fractal = ft_strdup(av);
	}
	else if (!ft_strcmp(av, "mandelbrot"))
	{
		mandelbrot(data);
		data->fractal = ft_strdup("mandelbrot");
	}
	mlx_put_image_to_window(data->ptr, data->win, data->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->zoom = 4.0;
	create_window(data);
	create_image(data);
	if (ac != 2 || available_fractals(av))
		error_phrase();
	fractale(av[1], data);
	hooks(data);
	mlx_loop(data->ptr);
	return (0);
}
