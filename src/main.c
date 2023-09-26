/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:14:22 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/26 06:15:46 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init(t_data *data)
{
		data->ptr = NULL;
		data->win = NULL ;
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
}

void	hooks(t_data *data)
{
	mlx_key_hook(data->win, mouse_and_esc, data);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_mouse_hook(data->win, zoom, data);
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
	if (data == NULL)
		exit(EXIT_FAILURE);
	init(data);
	data->zoom = 4.0;
	create_window_image(data);
	if (ac != 2 || error_fractals(av))
	{
		ft_error();
		free(data);
		exit(EXIT_FAILURE);
	}
	fractale(av[1], data);
	hooks(data);
	mlx_loop(data->ptr);
	free(data);
	return (0);
}

