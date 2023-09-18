/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:44:29 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/18 23:00:22 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	available_fractals(char **av)
{
	if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "julia.1")
		|| !ft_strcmp(av[1], "julia.2")
		|| !ft_strcmp(av[1], "mandelbrot"))
		return (0);
	return (1);
}

void	error_phrase(void)
{
	write(1, "---------------------------\n", 28);
	write(1, "     mandelbrot\n", 17);
	write(1, "     julia\n", 13);
	write(1, "    julia.1\n", 14);
	write(1, "    julia.2\n", 14);
	write(1, "----------------------------", 27);
	exit(EXIT_FAILURE);
}

int	exit_when_close(void)
{
	exit(EXIT_FAILURE);
	return (0);
}
