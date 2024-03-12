/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:05:57 by tkurukay          #+#    #+#             */
/*   Updated: 2024/03/12 17:01:06 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

void	file_control(char *map_name)
{
	int	len;
	int	fd;

	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'r' && map_name[len - 2] != 'e'
		&& map_name[len - 3] != 'b' && map_name[len - 4] != '.')
		exit_error("Error\nThe map is not .ber");
	else
	{
		fd = open(map_name, O_RDONLY);
		if (fd == -1)
			exit_error("Error\nMap not found");
		close(fd);
	}
}

int	map_checker(char **map)
{
	size_t	line_len;
	int		i;

	i = 0;
	line_len = ft_strlen(map[0]);
	if (only_one(map[0]) == 0)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != line_len)
			return (0);
		if (map[i][0] != '1' || map[i][line_len - 1] != '1')
			return (0);
		if (map_char_check(map[i]) == 0)
			return (0);
		i++;
	}
	if (char_counter(map, 'P') != 1 || char_counter(map, 'E') != 1)
		return (0);
	return (only_one(map[i - 1]));
}

int	map_check_nl(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	map_char_check(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P'
			&& map[i] != 'E' && map[i] != 'C')
			return (0);
		i++;
	}
	return (1);
}

int	char_counter(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}
