/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:03:31 by tkurukay          #+#    #+#             */
/*   Updated: 2024/03/12 17:01:06 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <stdlib.h>

int	map_read(char *map_name)
{
	int		fd;
	int		i;
	char	chr;
	size_t	file_len;

	i = 1;
	file_len = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while (i > 0)
	{
		i = read(fd, &chr, 1);
		if (i <= 0)
			break ;
		file_len += i;
	}
	close(fd);
	return (file_len);
}

char	**map_build(char *map_name, int len)
{
	int		i;
	int		fd;
	char	*map;
	char	**map_array;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(len * sizeof(char) + 1);
	if (!map)
		return (NULL);
	if (read(fd, map, len) <= 0)
		return (close(fd), free(map), NULL);
	close(fd);
	map[len] = '\0';
	if (map_check_nl(map))
		return (free(map), NULL);
	map_array = ft_split(map, '\n');
	free(map);
	while (map_array[i])
		i++;
	if (map_checker(map_array) == 0)
		return (free_map((void **)map_array, i), NULL);
	return (map_array);
}

int	only_one(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	player_xy(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->py = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'P')
			{
				data->px = j;
				data->py = i;
				return ;
			}
			j++;
		}
		i++;
	}
	free_exit("Player not found", data, 1);
}
