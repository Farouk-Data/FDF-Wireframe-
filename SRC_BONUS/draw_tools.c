/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:08:45 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/22 21:38:41 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inlcude/fdf_bonus.h"

void	plot_point(t_point *p, double x, double y, int color)
{
	p->x = x;
	p->y = y;
	p->color = color;
}

void img_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char *pixel;

	if(x < WINDOW_WIDTH && x > 0 && y < WINDOW_HEIGHT && y > 0)
	{
		pixel = fdf->img->addr + ((fdf->img->line_len * y) + x * (fdf->img->bpp / 8));
		*(int *)pixel = color;
	} 
}

// void	rotate_x(double *x, double *y, double z)
// {
// 	double	previous_x;
// 	double	previous_y;
// 	double	previous_z;

// 	previous_x = *x;
// 	previous_y = *y;
// 	previous_z = z;
// 	*x = previous_x;
// 	*y = previous_y*cos(THETA_X) + previous_z*sin(THETA_X);
// 	z = -previous_y*sin(THETA_X) + previous_z*cos(THETA_X);	
// }

// void	rotate_y(double *x, double *y, double z)
// {
// 	double	previous_x;
// 	double	previous_y;
// 	double	previous_z;

// 	previous_x = *x;
// 	previous_y = *y;
// 	previous_z = z;
// 	*x = previous_x*cos(THETA_Y) + previous_z*sin(THETA_Y);
// 	*y = previous_y;
// 	z = -previous_x*sin(THETA_Y) + previous_z*cos(THETA_Y);
// }

// void	rotate_z(double *x, double *y, double z)
// {
// 	double	previous_x;
// 	double	previous_y;
// 	double	previous_z;

// 	previous_x = *x;
// 	previous_y = *y;
// 	previous_z = z;
// 	*x = previous_x*cos(THETA_Z) - previous_y*sin(THETA_Z);
// 	*y = previous_x*sin(THETA_Z) + previous_y*cos(THETA_Z);
// 	z = previous_z;
// }

void iso(t_fdf *fdf, double *x, double *y, double z)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(fdf->theta_x);
	*y = -z + (previous_x + previous_y) * sin(fdf->theta_y);
}

void	zoom(t_fdf *fdf, t_point *p1, t_point *p2)
{
	p1->z = fdf->map_values[(int)p1->y][(int)p1->x];
	p2->z = fdf->map_values[(int)p2->y][(int)p2->x];
	p1->z *= fdf->elevation;
	p1->x *= fdf->zoom;
	p1->y *= fdf->zoom;
	p2->z *= fdf->elevation;
	p2->x *= fdf->zoom;
	p2->y *= fdf->zoom;
}


void	shifting(t_fdf *fdf, t_point *p1 , t_point *p2)
{
	p1->x += fdf->posx;
	p1->y += fdf->posy;
	p2->x += fdf->posx;
	p2->y += fdf->posy;
}
