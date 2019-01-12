/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:13:04 by fel-hita          #+#    #+#             */
/*   Updated: 2019/01/05 19:23:50 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_mlx_clear_window(int *data, t_npoint scr)
{
	int		i;
	int		size;

	i = -1;
	size = scr.x * scr.y;
	while (++i < size)
		data[i] = 0x000000;
}

void		ft_mlx_pixel_put(int *data, t_point p, t_npoint scr)
{
	int		i;

	if (p.x >= 0 && p.x < scr.x && p.y >= 0 && p.y < scr.y)
	{
		i = -1;
		data[p.y * scr.x + p.x] = p.color;
	}
	else
		;
}

void		ft_fdf_draw(t_fdf *f)
{
	t_point		p;
	t_npoint	temp;

	temp.x = -1;
	ft_mlx_clear_window(f->ptr.img.data, f->scr);
	while ((++temp.x < f->map.h) && (temp.y = -1))
	{
		while (++temp.y < f->map.w)
		{
			p = ft_iso(temp.x, temp.y, f);
			if (temp.y + 1 < f->map.w)
				draw_line(f->ptr.img.data, p,
						ft_iso(temp.x, temp.y + 1, f), f->scr);
			if (temp.x + 1 < f->map.h)
				draw_line(f->ptr.img.data, p,
						ft_iso(temp.x + 1, temp.y, f), f->scr);
		}
	}
	mlx_put_image_to_window(f->ptr.mlx_ptr, f->ptr.win_ptr, f->ptr.img.img_ptr,
			0, 0);
	ft_display_usage(f);
}

int			main(int argc, char *argv[])
{
	t_fdf	f;

	argc = (int)argc;
	ft_fdf_init(&f, argv[1]);
	ft_update_input(&f);
	ft_fdf_draw(&f);
	mlx_loop(f.ptr.mlx_ptr);
}
