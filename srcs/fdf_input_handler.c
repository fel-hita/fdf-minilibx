/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_input_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:36:06 by fel-hita          #+#    #+#             */
/*   Updated: 2019/01/05 22:47:47 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_error(int id)
{
	ft_putendl("Error :");
	if (id == 1)
		ft_putendl("Usage : ./fdf 'File_Path'");
	else if (id == 2)
		ft_putendl("File contains a single line");
	exit(EXIT_FAILURE);
}

void		ft_fdf_init(t_fdf *f, char *file_name)
{
	t_npoint	scr;

	get_map(&f->map, file_name);
	scr.x = (f->map.w * 25 + 400);
	scr.y = (f->map.h * 25 + 300);
	f->scr.x = scr.x > SCR_WIDTH ? SCR_WIDTH : scr.x;
	f->scr.y = scr.y > SCR_HEIGHT ? SCR_HEIGHT : scr.y;
	f->u.x = (f->scr.x / 2 > f->map.w * 25 / 2) ?\
			(f->scr.x / 2 - f->map.w * 25 / 2) : 50;
	f->u.y = (f->scr.y / 2 > f->map.h * 25 / 2) ?\
			(f->scr.y / 2 - f->map.h * 25 / 2) : 20;
	f->angle = 0.0;
	f->delta = 0.05;
	f->rotate = 0;
	f->iso = ISO1;
	f->pro = 0;
	f->s = 0;
	f->h = 1;
	f->c = 0;
	ft_fdf_init_helper(f, scr);
}

void		ft_fdf_init_helper(t_fdf *f, t_npoint scr)
{
	f->z = (scr.x >= SCR_WIDTH || scr.y >= SCR_HEIGHT) ? 1.0 : 10.0;
	f->sc = (scr.x >= SCR_WIDTH || scr.y >= SCR_HEIGHT) ? 3 : 10;
	f->ptr.mlx_ptr = mlx_init();
	f->ptr.win_ptr = \
		mlx_new_window(f->ptr.mlx_ptr, f->scr.x, f->scr.y, "FDF 1337");
	f->ptr.img.img_ptr = \
		mlx_new_image(f->ptr.mlx_ptr, f->scr.x, f->scr.y);
	f->ptr.img.data = \
		(int *)mlx_get_data_addr(f->ptr.img.img_ptr, &f->ptr.img.bpp,\
			&f->ptr.img.size_l, &f->ptr.img.endian);
}

void		get_map(t_map *m, char *filename)
{
	int			y;
	int			fd;
	char		*line;

	fd = open(filename, O_RDONLY);
	y = 0;
	m->w = 0;
	if (get_next_line(fd, &line) == 1 && line)
	{
		map_filler(m, line, y++);
		while (get_next_line(fd, &line))
			map_filler(m, line, y++);
		m->h = y;
	}
	else
		ft_error(1);
}

void		map_filler(t_map *m, char *line, int i)
{
	int		j;
	char	**tab;
	char	*temp;

	j = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[j])
	{
		m->tab[i][j].z = (double)ft_atoi(tab[j]);
		temp = ft_strstr(tab[j], "0x");
		if (temp)
			m->tab[i][j].color = ft_atoi_col_16(ft_capitalize(temp));
		else
			m->tab[i][j].color = 0xFFFFFF;
		temp = NULL;
		j++;
	}
	if (j && !m->w)
		m->w = j;
}
