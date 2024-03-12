/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:23:52 by tkurukay          #+#    #+#             */
/*   Updated: 2024/03/12 17:01:05 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>

int	mlx_exit(t_data *data, char *str)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->bground)
		mlx_destroy_image(data->mlx, data->bground);
	return (free_exit(str, data, 1), 1);
}

void	exit_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	free_exit(char *str, t_data *data, int flag)
{
	if (flag == 1)
	{
		free_map((void **)data->map->map, data->map->map_h);
	}
	free(data->map);
	free(data);
	ft_printf("%s\n", str);
	exit(0);
}

void	free_map(void **map, int len)
{
	int	i;

	i = 0;
	while (len > i)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_exit(data, "Exit");
	return (0);
}
