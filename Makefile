# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 15:00:39 by ayagoumi          #+#    #+#              #
#    Updated: 2019/12/29 01:02:52 by ayagoumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

lib = ./libft/libft.a

SRCS = ./srcs/sets_hook.c ./srcs/zoom.c ./srcs/hook.c ./srcs/colors.c \
		./srcs/utils.c ./srcs/thread.c ./srcs/sets.c ./srcs/assi_funct.c \
		./srcs/errors.c ./srcs/hook1.c ./srcs/maps.c ./srcs/sets2.c \
		./srcs/sets3.c ./srcs/threading.c ./srcs/main.c

CC = gcc

INC = ./srcs/fractol.h

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

FRAM = -lmlx -framework OpenGL -framework AppKit -lpthread

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@echo "\033[2;36m"
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) $(FRAM) $(lib)
	@echo "fractol: executable file is ready"
	@echo "\033[0m"
	@echo "\033[44m ------------- Fractal ----------- \033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  1 - mandelbrot                 |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  2 - mandelbrot2                |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  3 - mandelbrot3                |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  5 - julia                      |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  6 - burningship                |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  6 - mandelbar_5th              |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  7 - mandelbar                  |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  8 - celtic_mandelbrot          |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  9 - batman                     |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  10 - madelbrot_inception       |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  11 - double_tear_drop          |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m|  12 - reverse_mandelbrot        |\033[0m"
	@echo "\033[44m|                                 |\033[0m"
	@echo "\033[44m --------------------------------- \033[0m\n"
	@echo "\n\033[01;33mNote : use only one or 2 arguments\033[0m\n"
	@echo "\033[41m./fractol <name_of_fractal>\033[0m"
	@echo "\033[41m./fractol <number_of_the_fractal>\033[0m"

clean:
	@echo "\033[2;32m"
	@rm -rf $(OBJ) 2> /dev/null || true
	@make -C libft clean 2> /dev/null || true
	@echo "fractol: all resources deleted"
	@echo "\033[0m"

fclean: clean
	@echo "\033[2;34m"
	@rm -rf $(NAME) 2> /dev/null || true
	@make -C libft fclean 2> /dev/null || true
	@echo "fractol: all resources deleted"
	@echo "\033[0m"

re: fclean all