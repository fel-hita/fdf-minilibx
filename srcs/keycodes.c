/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 23:08:39 by fel-hita          #+#    #+#             */
/*   Updated: 2019/01/05 20:15:09 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_key_pressed_helper(int *keycode, t_fdf *f)
{
	if (*keycode == MLX_SCANCODE_ESCAPE)
		exit(EXIT_FAILURE);
	else if (*keycode == MLX_SCANCODE_F1 && (f->rotate = 1))
		f->delta = -0.05;
	else if (*keycode == MLX_SCANCODE_F2 && (f->rotate = 1))
		f->delta = 0.05;
	else if (*keycode == MLX_SCANCODE_F3 && (f->rotate = 2))
		f->delta = -0.05;
	else if (*keycode == MLX_SCANCODE_F4 && (f->rotate = 2))
		f->delta = 0.05;
	else if (*keycode == MLX_SCANCODE_F5 && (f->rotate = 3))
		f->delta = -0.05;
	else if (*keycode == MLX_SCANCODE_F6 && (f->rotate = 3))
		f->delta = 0.05;
	else
		f->rotate = 0;
	f->angle += f->delta;
	return (0);
}

int		ft_range_color(double z)
{
	int		k;
	int		tab[N_COLORS];

	k = ((int)z) % N_COLORS;
	tab[0] = 0xFFFFFF;
	tab[1] = 0x362312;
	tab[2] = 0x311432;
	tab[3] = 0x222021;
	tab[4] = 0x420D09;
	tab[5] = 0x3E424B;
	tab[6] = 0x544C4A;
	tab[7] = 0x363636;
	tab[8] = 0x48494A;
	tab[9] = 0x043927;
	tab[10] = 0x4B5320;
	tab[11] = 0x81007F;
	tab[12] = 0x2B1700;
	tab[13] = 0x000080;
	tab[14] = 0xFF0090;
	tab[15] = 0xFFFDD0;
	tab[16] = 0xFCD12A;
	tab[17] = 0x98FB98;
	if (k <= 17)
		return (tab[k]);
	return (0xFF00FF);
}

int		ft_key_pressed(int keycode, void *params)
{
	t_fdf *f;

	f = (t_fdf *)params;
	ft_key_pressed_helper(&keycode, f);
	if (keycode == MLX_SCANCODE_P)
		f->pro = ++f->pro % 4;
	if (keycode == MLX_SCANCODE_A)
		f->iso += 0.05;
	if (keycode == MLX_SCANCODE_S)
		f->s = ++f->s % 3;
	if (keycode == MLX_SCANCODE_C)
		f->c = ++f->c % 2;
	if (keycode == MLX_SCANCODE_H)
		f->h = ++f->h % 2;
	ft_key_pressed2(keycode, params);
	ft_fdf_draw(f);
	return (0);
}

int		ft_key_pressed2(int keycode, void *params)
{
	t_fdf *f;

	f = (t_fdf *)params;
	ft_key_pressed_helper(&keycode, f);
	if (keycode == MLX_SCANCODE_UP)
		f->u.y -= 1;
	if (keycode == MLX_SCANCODE_DOWN)
		f->u.y += 1;
	if (keycode == MLX_SCANCODE_LEFT)
		f->u.x -= 1;
	if (keycode == MLX_SCANCODE_RIGHT)
		f->u.x += 1;
	if (keycode == MLX_SCANCODE_PAD_ADD)
		f->sc += 1;
	if (keycode == MLX_SCANCODE_PAD_SUB)
		f->sc -= 1;
	ft_fdf_draw(f);
	return (0);
}

int		ft_mouse_pressed(int button, int x, int y, void *params)
{
	t_fdf *f;

	f = (t_fdf *)params;
	if (button == MLX_BUTTON_RIGHT)
	{
		f->u.x = x;
		f->u.y = y;
	}
	if (button == MLX_BUTTON_LEFT)
	{
		f->u.x = x;
		f->u.y = y;
	}
	if (button == MLX_BUTTON_UP)
		f->z += 0.5;
	if (button == MLX_BUTTON_DOWN)
		f->z -= 0.5;
	ft_fdf_draw(f);
	return (0);
}
