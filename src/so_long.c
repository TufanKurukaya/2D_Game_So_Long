/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:54 by tkurukay          #+#    #+#             */
/*   Updated: 2024/03/12 16:59:40 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	map_w_h(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
		i++;
	data->map->map_h = i;
	data->map->map_w = ft_strlen(data->map->map[0]);
}

t_data	*datat_init(char *map_name)
{
	t_data	*data;
	int		map_len;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit_error("Error\nMalloc error");
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
	{
		free(data);
		exit_error("Error\nMalloc error");
	}
	map_len = map_read(map_name);
	data->map->map = map_build(map_name, map_len);
	if (!data->map->map)
		free_exit("Error\nMap not created", data, 0);
	data->cc = char_counter(data->map->map, 'C');
	if (data->cc == 0)
		free_exit("Error\nNo collectibles", data, 1);
	data->temp = data->cc + 1;
	map_w_h(data);
	player_xy(data);
	data->mc = 0;
	return (data);
}

int	put_xml(t_data *data)
{
	render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		data->px * PIXEL, data->py * PIXEL);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		file_control(av[1]);
		data = datat_init(av[1]);
		create_virtual_map(data, 0, 0);
		init_mlx(data);
		render(data);
		mlx_hook(data->win, 2, 0, keyboard, data);
		mlx_hook(data->win, 17, 0, close_window, data);
		mlx_loop_hook(data->mlx, put_xml, data);
		mlx_loop(data->mlx);
	}
	else
		exit_error("Error\nInvalid number of arguments");
}
