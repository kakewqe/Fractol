/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <zack@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:15:24 by zachamou          #+#    #+#             */
/*   Updated: 2023/09/27 18:18:25 by zack             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_SIZE 900
# define ESC_KEY 65307
# define MOUSE_UP 4
# define MOUSE_DOWN 5


typedef struct s_data
{
	void	*ptr;
	void	*win;
	void	*img;
	double	x;
	double	y;
	double	re;
	double	im;
	double	temp;
	double	zoom;
	double	cons_re;
	double	cons_im;
	char	*addr;
	char	*fractal;
	int		j;
	int		n;
	int		i;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	double	min_r;
	double	min_i;
	double 	max_r;
	double 	max_i;
	
}			t_data;

double	ft_atof(const char *str);

int			ft_close(t_data *data);
void 		fractale(char **av, int ac, t_data *data);
void		create_window_image(t_data *data);

void		my_putpixel(t_data *data, int x, int y, int color);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);

int			error_fractals(char **av);
void		ft_error(void);

void		mandelbrot(t_data *data);
int			iterate_mandelbrot(t_data *data);

void		julia(t_data *data);
int			iterate_julia(t_data *data);

int			mouse_and_esc(int keycode, t_data *data);
int			zoom(int keycode, int x, int y, t_data *data);

#endif
