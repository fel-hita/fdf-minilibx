/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 08:51:23 by fel-hita          #+#    #+#             */
/*   Updated: 2019/01/05 22:47:03 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "keycode.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define ISO2 0.523599
# define ISO1 0.46373398
# define SCR_WIDTH 2400
# define SCR_HEIGHT 1600
# define mAX_SIZE 500
# define N_COLORS 18

typedef struct	s_point
{
	int			x;
	int			y;
	int			color;
}				t_point;

typedef struct	s_npoint
{
	int			x;
	int			y;

}				t_npoint;

typedef struct	s_dot
{
	double		z;
	int			color;
}				t_dot;

typedef struct	s_img
{
	void		*img_ptr;
	void		*data;
	int			endian;
	int			size_l;
	int			bpp;
}				t_img;

typedef struct	s_ptr
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_ptr;

typedef struct	s_map
{
	int			w;
	int			h;
	t_dot		tab[mAX_SIZE][mAX_SIZE];
}				t_map;

typedef	struct	s_fdf
{
	t_ptr		ptr;
	t_npoint	u;
	t_map		map;
	double		z;
	int			sc;
	int			pro;
	int			s;
	int			h;
	int			c;
	int			rotate;
	double		angle;
	double		iso;
	double		delta;
	t_npoint	scr;
}				t_fdf;

int				get_next_line(int const fd, char **line);
char			**ft_strsplit(char const *s, char c);
int				ft_atoi(const char *str);
void			ft_putnbr(int n);
void			map_filler(t_map *m, char *line_arr, int i);
void			get_map(t_map *m, char *filename);
void			ft_fdf_init(t_fdf *f, char *file_name);
void			ft_fdf_init_helper(t_fdf *f, t_npoint scr);
void			ft_fdf_draw(t_fdf *f);
int				ft_key_pressed(int keycode, void *params);
int				ft_key_pressed2(int keycode, void *params);
int				ft_mouse_pressed(int button, int x, int y, void *params);
int				ft_update_input(t_fdf *f);
int				ft_close(void *params);
int				ft_range_color(double z);
t_point			ft_iso(int y, int x, t_fdf *f);
void			ft_projection(t_point *p, t_npoint q, double z, t_fdf *f);
void			ft_rotate_x(t_npoint *p, double *z, double angle);
void			ft_rotate_y(t_npoint *p, double *z, double angle);
void			ft_rotate_z(t_npoint *p, double *z, double angle);
int				ft_get_color(t_point current, t_point start, t_point end,
		t_point delta);
char			*ft_capitalize(char *str);
int				ft_atoi_col_16(char *str);
char			*ft_projection_text(int n);
double			ft_pow(double nb, int puiss);
char			*ft_itoaf(long double nb, int precision);
void			ft_display_usage(t_fdf *f);
void			ft_mlx_pixel_put(int *data, t_point p, t_npoint scr);
void			draw_line(int *ptr, t_point p1, t_point p2, t_npoint scr);
void			debug(t_fdf *f);
void			printab(t_fdf *f);

#endif
