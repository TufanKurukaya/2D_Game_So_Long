/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:36:03 by tkurukay          #+#    #+#             */
/*   Updated: 2024/03/12 17:01:07 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 100
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_map
{
	char	**map;
	int		map_w;
	int		map_h;
}	t_map;

typedef struct s_data
{
	int		px;
	int		py;
	int		cc;
	int		mc;
	int		temp;
	void	*mlx;
	void	*win;
	void	*player;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*bground;
	t_map	*map;
}	t_data;

int		mlx_exit(t_data *data, char *str);
int		map_checker(char **map);
int		map_check_nl(char *map);
int		map_read(char *map_name);
int		only_one(char *map_line);
int		map_char_check(char *map);
int		char_counter(char **map, char c);
int		keyboard(int keycode, t_data *game);
int		close_window(t_data *data);

char	**map_build(char *map_name, int len);

void	render(t_data *data);
void	exit_error(char *str);
void	init_mlx(t_data *data);
void	player_xy(t_data *data);
void	file_control(char *map_name);
void	free_map(void **vmap, int len);
void	free_exit(char *str, t_data *data, int flag);
void	create_virtual_map(t_data *data, int x, int y);
void	check_map_played(int **vmap, t_data *data, int x, int y);

t_data	*datat_init(char *map_name);

#endif
