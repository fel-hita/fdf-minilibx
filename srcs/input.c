/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 23:01:06 by fel-hita          #+#    #+#             */
/*   Updated: 2019/01/05 20:04:27 by fel-hita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_close(void *params)
{
	(void)params;
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_update_input(t_fdf *f)
{
	mlx_hook(f->ptr.win_ptr, 2, 0, ft_key_pressed, f);
	mlx_hook(f->ptr.win_ptr, 4, 0, ft_mouse_pressed, f);
	mlx_hook(f->ptr.win_ptr, 17, 0, ft_close, f);
	return (0);
}

void	ft_display_usage(t_fdf *f)
{
	char	*text;

	if (f->h)
	{
		text = ft_strdup("Use mouse to change FDF initial coordinations");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.win_ptr, 5, 2, 0xDC143C, text);
		free(text);
		text = ft_strdup("Use arrows to move the FDF around");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.win_ptr, 5, 22, 0xFFA500, text);
		free(text);
		text = ft_strdup("Use PAD +, PAD- for zoom-in zoom-out respectively");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.win_ptr, 5, 42, 0xFFD700, text);
		free(text);
		text = ft_strdup("Use A, SPACE, F keys F1, F2 ....");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.win_ptr, 5, 62, 0xADFF2F, text);
		free(text);
		text = ft_strdup("Use H to show/hide help menu");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.win_ptr, 5, 82, 0x00FF00, text);
		free(text);
		text = ft_strdup("Autors : Fdf By Fel-Hita and Afaddoul");
		mlx_string_put(f->ptr.mlx_ptr, f->ptr.win_ptr, 5, 102, 0x00FA9A, text);
		free(text);
	}
}
