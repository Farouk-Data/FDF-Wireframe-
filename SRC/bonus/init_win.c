/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:09:30 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/24 03:08:36 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	resize_map(t_fdf *fdf)
{
	if (fdf->word_count < 50 && fdf->line_count < 50)
	{
		fdf->zoom = 30;
		fdf->elevation = 2;
	}
	else if (fdf->word_count < 100 && fdf->line_count < 100)
	{
		fdf->zoom = 15;
		fdf->elevation = 1;
	}
	else if (fdf->word_count < 400 && fdf->line_count < 400)
	{
		fdf->zoom = 6;
		fdf->elevation = 1;
	}
	else
	{
		fdf->zoom = 2;
		fdf->elevation = 1;
	}
}

int	init_win(t_fdf *fdf)
{
	fdf->iso = 1;
	fdf->theta_x = 0.523599;
	fdf->theta_y = 0.523599;
	resize_map(fdf);
	fdf->posx = (WINDOW_WIDTH) / 2;
	fdf->posy = WINDOW_HEIGHT / 2 - (fdf->word_count * fdf->zoom / 2);
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		return (MLX_ERROR);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!fdf->win_ptr)
	{
		free(fdf);
		return (MLX_ERROR);
	}
	fdf->img->img_ptr = mlx_new_image(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img_ptr,
			&fdf->img->bpp, &fdf->img->line_len, &fdf->img->endian);
	return (0);
}
