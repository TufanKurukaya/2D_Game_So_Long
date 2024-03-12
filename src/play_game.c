/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:06:50 by tkurukay          #+#    #+#             */
/*   Updated: 2024/03/12 17:01:03 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"

void	init_mlx(t_data *data)
{
	int	x;
	int	y;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map->map_w * PIXEL,
			data->map->map_h * PIXEL, "so_long");
	data->player = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &y, &x);
	data->coin = mlx_xpm_file_to_image(data->mlx, "textures/coin.xpm", &y, &x);
	data->exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm", &y, &x);
	data->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &y, &x);
	data->bground = mlx_xpm_file_to_image(data->mlx,
			"textures/bground.xpm", &y, &x);
	if (!data->player || !data->coin || !data->exit
		|| !data->wall || !data->bground || !data->mlx || !data->win)
		mlx_exit(data, "Error\nTextures not loaded");
}

int	keyboard(int keycode, t_data *data)
{
	if (keycode == ESC)
		mlx_exit(data, "Exit");
	else if (keycode == W && data->map->map[data->py - 1][data->px] != '1')
		data->py--;
	else if (keycode == A && data->map->map[data->py][data->px - 1] != '1')
		data->px--;
	else if (keycode == S && data->map->map[data->py + 1][data->px] != '1')
		data->py++;
	else if (keycode == D && data->map->map[data->py][data->px + 1] != '1')
		data->px++;
	else
		return (0);
	ft_printf("Moves: %d\n", ++data->mc);
	if (data->map->map[data->py][data->px] == 'C')
	{
		data->cc--;
		data->map->map[data->py][data->px] = '0';
	}
	if (data->map->map[data->py][data->px] == 'E' && data->cc == 0)
		mlx_exit(data, "You won!");
	return (0);
}

void	render(t_data *data)
{
	int	x;
	int	y;

	mlx_clear_window(data->mlx, data->win);
	y = -1;
	while (++y < data->map->map_h)
	{
		x = -1;
		while (++x < data->map->map_w)
		{
			if (data->map->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->wall, x * PIXEL, y * PIXEL);
			else
				mlx_put_image_to_window(data->mlx, data->win,
					data->bground, x * PIXEL, y * PIXEL);
			if (data->map->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->exit, x * PIXEL, y * PIXEL);
			else if (data->map->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->coin, x * PIXEL, y * PIXEL);
		}
	}
}
