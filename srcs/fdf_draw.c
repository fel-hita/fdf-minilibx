/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 00:52:08 by fel-hita          #+#    #+#             */
/*   Updated: 2019/01/05 00:57:25 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_mlx_draw_helper(t_point *p1, t_point start)
{
	p1->x = start.x;
	p1->y = start.y;
	p1->color = start.color;
}

void	ft_mlx_draw_octant1(int *data, t_point start, t_point p2, t_npoint scr)
{
	t_point		dp;
	t_npoint	pincr;
	t_point		p1;
	int			error;
	int			i;

	i = -1;
	ft_mlx_draw_helper(&p1, start);
	pincr.x = p1.x < p2.x ? 1 : -1;
	pincr.y = p1.y < p2.y ? 1 : -1;
	dp.x = abs(p2.x - p1.x);
	dp.y = abs(p2.y - p1.y);
	error = dp.x / 2;
	while (++i <= dp.x)
	{
		p1.x += pincr.x;
		error += dp.y;
		if (error > dp.x)
		{
			error -= dp.x;
			p1.y += pincr.y;
		}
		p1.color = ft_get_color(p1, start, p2, dp);
		ft_mlx_pixel_put(data, p1, scr);
	}
}

void	ft_mlx_draw_octant2(int *data, t_point start, t_point p2, t_npoint scr)
{
	t_point		dp;
	t_npoint	pincr;
	t_point		p1;
	int			error;
	int			i;

	i = -1;
	ft_mlx_draw_helper(&p1, start);
	pincr.x = p1.x < p2.x ? 1 : -1;
	pincr.y = p1.y < p2.y ? 1 : -1;
	dp.x = abs(p2.x - p1.x);
	dp.y = abs(p2.y - p1.y);
	error = dp.y / 2;
	while (++i <= dp.y)
	{
		p1.y += pincr.y;
		error += dp.x;
		if (error > dp.y)
		{
			error -= dp.y;
			p1.x += pincr.x;
		}
		p1.color = ft_get_color(p1, start, p2, dp);
		ft_mlx_pixel_put(data, p1, scr);
	}
}

void	draw_line(int *data, t_point p1, t_point p2, t_npoint scr)
{
	ft_mlx_pixel_put(data, p1, scr);
	ft_mlx_pixel_put(data, p2, scr);
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
		ft_mlx_draw_octant1(data, p1, p2, scr);
	else
		ft_mlx_draw_octant2(data, p1, p2, scr);
}
