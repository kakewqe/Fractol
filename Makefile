# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zachamou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 23:41:42 by zachamou          #+#    #+#              #
#    Updated: 2023/09/22 23:44:59 by zachamou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LDFLAGS = -L./inc/minilibx-linux -lmlx -lX11 -lXext -lm 
CFLAGS = -Wall -Werror -Wextra -g -I./inc/minilibx-linux
SRCS = src/mandelbrot.c src/julia.c  src/main.c src/mouv.c src/ft_strcmp.c src/ft_strdup.c src/exit.c
OBJS = $(SRCS:.c=.o)

all: minilibx $(NAME)
	@echo "//////////**Conpilation fractal OK**/////////////"
	rm -rf $(OBJS)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

minilibx : 
	@echo "/////////**Conpilation minilibx OK**//////////////"
	@cd inc/minilibx-linux && make

.PHONY: all clean fclean re
