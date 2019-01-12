/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 22:22:06 by fel-hita          #+#    #+#             */
/*   Updated: 2019/01/03 18:52:37 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_rotate_y(t_npoint *p, double *z, double angle)
{
	int		prev_x;
	int		prev_y;
	double	prev_z;

	prev_x = p->x;
	prev_y = p->y;
	prev_z = *z;
	p->x = prev_x;
	p->y = prev_y * cos(angle) - prev_z * sin(angle);
	*z = (prev_y * sin(angle)) + prev_z * cos(angle);
}

void		ft_rotate_x(t_npoint *p, double *z, double angle)
{
	int		prev_x;
	int		prev_y;
	double	prev_z;

	prev_x = p->x;
	prev_y = p->y;
	prev_z = *z;
	p->x = prev_x * cos(angle) + prev_z * sin(angle);
	*z = -prev_x * sin(angle) + prev_z * cos(angle);
}

void		ft_rotate_z(t_npoint *p, double *z, double angle)
{
	int		prev_x;
	int		prev_y;
	double	prev_z;

	prev_x = p->x;
	prev_y = p->y;
	prev_z = *z;
	p->x = prev_x * cos(angle) - prev_y * sin(angle);
	p->y = prev_x * sin(angle) + prev_y * cos(angle);
}
