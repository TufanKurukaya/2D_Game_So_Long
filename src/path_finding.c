/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:18:52 by tkurukay          #+#    #+#             */
/*   Updated: 2024/03/12 17:01:03 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	check_map_played(int **vmap, t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'C' || data->map->map[y][x] == 'E')
		data->temp--;
	if (data->map->map[y - 1][x] != '1' && vmap[y - 1][x] == 0)
	{
		vmap[y - 1][x] = 1;
		check_map_played(vmap, data, x, y - 1);
	}
	if (data->map->map[y + 1][x] != '1' && vmap[y + 1][x] == 0)
	{
		vmap[y + 1][x] = 1;
		check_map_played(vmap, data, x, y + 1);
	}
	if (data->map->map[y][x - 1] != '1' && vmap[y][x - 1] == 0)
	{
		vmap[y][x - 1] = 1;
		check_map_played(vmap, data, x - 1, y);
	}
	if (data->map->map[y][x + 1] != '1' && vmap[y][x + 1] == 0)
	{
		vmap[y][x + 1] = 1;
		check_map_played(vmap, data, x + 1, y);
	}
}

void	create_virtual_map(t_data *data, int x, int y)
{
	int	**vmap;

	vmap = (int **)malloc(sizeof(int *) * data->map->map_h + 1);
	if (!vmap)
		free_exit("Malloc failed",data, 1);
	while (y < data->map->map_h)
	{
		vmap[y] = (int *)malloc(sizeof(int) * data->map->map_w + 1);
		if (!vmap[y])
		{
			free_map((void **)vmap, y);
			free_exit("Malloc failed",data, 1);
		}
		x = 0;
		while (x < data->map->map_w)
		{
			vmap[y][x] = 0;
			x++;
		}
		y++;
	}
	check_map_played(vmap, data, data->px, data->py);
	if (data->temp != 0)
		free_exit("Error\nCollectibles is not accessible", data, 1);
	free_map((void **)vmap, y);
}
