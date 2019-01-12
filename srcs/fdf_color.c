/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 00:07:51 by fel-hita          #+#    #+#             */
/*   Updated: 2019/01/04 20:35:39 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	ft_percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		ft_get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		ft_get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = ft_percent(start.x, end.x, current.x);
	else
		percentage = ft_percent(start.y, end.y, current.y);
	red = ft_get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = ft_get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = ft_get_light((start.color & 0xFF), end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | (blue));
}

char	*ft_capitalize(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return (str);
}

int		ft_atoi_col_16(char *str)
{
	int		i;
	int		number;
	int		color;

	i = 2;
	number = 0;
	color = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			number += str[i] - '0';
		else
			number += (10 + str[i] - 'A');
		if (ft_isdigit(str[i + 1]) || (str[i] >= 'A' && str[i + 1] <= 'F'))
			number *= 16;
		++i;
	}
	return (number);
}
