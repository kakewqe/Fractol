/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachamou <zachamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:15:24 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/20 12:11:56 by zachamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define WIN_SIZE 900
# define ESC_KEY 65307
# define MOUSE_UP 4
# define MOUSE_DOWN 5

typedef struct s_data
{
	void	*ptr;
	void	*win;
	void	*img;
	float	x;
	float	y;
	float	re;
	float	im;
	float	temp;
	float	zoom;
	float	c_re;
	float	c_im;
	char	*addr;
	char	*fractal;
	int		j;
	int		n;
	int		i;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
}		t_data;

void	fractale(char *av, t_data *p);
void	create_image(t_data *p);
void	create_window(t_data *p);
int		exit_when_close(void);

void	my_putpixel(t_data *p, int x, int y, int color);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);

int		error_fractals(char **av);
void	error_phrase(void);

void	mandelbrot(t_data *p);
int		iterate_mandelbrot(t_data *p);

void	julia(char *av, t_data *data);
int		iterate_julia(char *av, t_data *data);

int		mouse_and_esc(int keycode, t_data *data);
int		zoom(int keycode, int x, int y, t_data *p);

#endif
