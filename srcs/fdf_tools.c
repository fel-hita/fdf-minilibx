/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf-tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:14:09 by fel-hita          #+#    #+#             */
/*   Updated: 2019/01/05 01:00:44 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	ft_iso(int y, int x, t_fdf *f)
{
	t_npoint	q;
	t_point		p;
	double		z;

	z = f->z * f->map.tab[y][x].z;
	q.x = f->sc * x;
	q.y = f->sc * y;
	if (f->c)
		p.color = ft_range_color(z);
	else
		p.color = f->map.tab[y][x].color;
	if (f->s == 0)
		f->iso = ISO1;
	else if (f->s == 1)
		f->iso = ISO2;
	if (f->rotate == 1)
		ft_rotate_x(&q, &z, f->angle);
	else if (f->rotate == 2)
		ft_rotate_y(&q, &z, f->angle);
	else if (f->rotate == 3)
		ft_rotate_z(&q, &z, f->angle);
	ft_projection(&p, q, z, f);
	return (p);
}

void	ft_projection(t_point *p, t_npoint q, double z, t_fdf *f)
{
	if (f->pro == 0)
	{
		p->x = q.x + f->u.x;
		p->y = q.y + f->u.y;
	}
	else if (f->pro == 1)
	{
		p->x = q.x + 1 + z + f->u.x;
		p->y = q.y + 0.5 * z + f->u.y;
	}
	else
	{
		p->x = (q.x - q.y) * cos(f->iso) + f->u.x;
		p->y = -z + (q.x + q.y) * sin(f->iso) + f->u.y;
	}
}

char	*ft_itoaf(long double nb, int precision)
{
	int				n;
	int				i;
	char			*temp;

	i = 0;
	n = nb;
	temp = ft_strdup(ft_itoa(n));
	nb = nb > 0 ? nb - n : -(nb - n);
	temp = ft_strjoin(temp, ".");
	while (nb < 0.1 && nb > -0.1 && i < precision - 1)
	{
		nb *= 10;
		i++;
	}
	n = nb * ft_pow(10, precision - i);
	n = (nb * ft_pow(10, precision - i) - n > 0.01) ? n + 1 : n;
	temp = ft_strjoin(temp, ft_itoa(n));
	return (temp);
}

double	ft_pow(double nb, int puiss)
{
	double	res;

	res = 1.0;
	if (puiss == 0)
		return (1);
	if (puiss == 1)
		return (nb);
	if (puiss < 0)
	{
		puiss = -puiss;
		nb = 1.0 / nb;
	}
	while (puiss)
	{
		if (puiss & 1)
			res *= nb;
		puiss >>= 1;
		nb *= nb;
	}
	return (res);
}
