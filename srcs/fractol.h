/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:35:08 by ayagoumi          #+#    #+#             */
/*   Updated: 2019/12/29 00:35:48 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include "math.h"
# include <pthread.h>
# include <stdio.h>
# define WIN_WIDTH 800
# define WIN_HEIGTH 800

typedef struct			s_img
{
	void				*img_ptr;
	int					*data;
	int					size_l;
	int					bpp;
	int					endian;
}						t_img;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win;
	t_img				img;
}						t_mlx;

typedef struct			s_fractol
{
	t_mlx				mlx;
	int					nmax;
	long double			re_min;
	long double			re_max;
	long double			im_min;
	long double			im_max;
	long double			zoom_fract;
	int					x;
	int					y;
	int					nb;
	int					fract;
	char				*name;
	int					(*f)(int, int, int, struct s_fractol *);
	double				color;
	double				a[4];
	double				b[4];
	double				mv_x_im;
	double				mv_y_im;
	double				mv_x_re;
	double				mv_y_re;
	int					l;
	int					m;
}						t_fractol;

typedef struct			s_ll
{
	long double			cr;
	long double			ci;
}						t_ll;

double					map(int position, int max_wh, double new_min_scope
		, double new_max_scope);
void					error_msg(int nb, char *av);
int						assi_fonct1(char *av, t_fractol *h);
int						assi_fonct2(char *av, t_fractol *h);
int						assi_fonct3(char *av, t_fractol *h);
int						assi_fonct4(char *av, t_fractol *h);
int						assi_fonct(char *av, t_fractol *h);
void					one_arg(char *av, t_fractol *h);
void					sub_arg_two(t_fractol *h1, t_fractol *h2);
void					two_arg(char *av1, char *av2, t_fractol *h1
		, t_fractol *h2);
void					*thread1(void *h1);
void					*thread2(void *h1);
void					*thread3(void *h1);
void					*thread4(void *h1);
int						threading(t_fractol *h);
int						thread_hook(int x, int y, t_fractol *h);
void					show_infos(t_fractol *h);
void					show_infos2(t_fractol *h);
void					show_infos3(t_fractol *h);
int						zoom_in_hook(int button, int x, int y, t_fractol *h);
int						hook_sets1(int key, t_fractol *h);
int						hook_sets2(int key, t_fractol *h);
int						hook_sets3(int key, t_fractol *h);
int						hook_sets4(int key, t_fractol *h);
int						hook_sets5(int key, t_fractol *h);
int						hook(int key, t_fractol *h);
int						rgb(int r, int g, int b);
int						rgb1(int max, int n, t_fractol *h);
int						mandelbrot_set(int x, int y, int m, t_fractol *h);
int						mandelbrot2_set(int x, int y, int m, t_fractol *h);
int						mandelbrot3_set(int x, int y, int m, t_fractol *h);
int						burningship_set(int x, int y, int m, t_fractol *h);
int						mandelbar_5th_set(int x, int y, int m, t_fractol *h);
int						mandelbar_set(int x, int y, int m
		, t_fractol *h);
int						celtic_mandelbrot_set(int x, int y, int m
		, t_fractol *h);
int						batman_set(int x, int y, int m, t_fractol *h);
int						madelbrot_inception_set(int x, int y, int m
		, t_fractol *h);
int						double_tear_drop_set(int x, int y, int m
		, t_fractol *h);
int						reverse_mandelbrot_set(int x, int y, int m
		, t_fractol *h);
int						julia_set(int x, int y, int m, t_fractol *h);
int						julia_update(int x, int y, int m, t_fractol *h);
void					init_struct(t_fractol *h);
void					destroy_image(t_fractol *h);
double					homothetic_transformation(double start, double end
		, double k);
void					zoom(t_fractol *h, double x, double y);
#endif
