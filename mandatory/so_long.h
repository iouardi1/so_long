/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:44:07 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/17 04:13:17 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_player {
	int		x;
	int		y;
	int		eaten_collect;
	char	*move;
	int		count_moves;
}	t_player;

typedef struct s_mapy {
	int		height;
	int		width;
	int		v_ntiles;
	int		h_ntiles;
	char	**arr;
	int		collects;
	void	*wall;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*player_down;
	void	*collect;
	void	*exit;
}	t_mapy;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}	t_data;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_game {
	t_player	*tanjiro;
	t_data		img;
	t_mlx		mlx;
	t_mapy		*mapy;
}	t_game;

void	draw_map(t_game *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	read_the_map(t_game *game, int fd);
int		try(int a, t_game *game);
void	draw_player(t_game *game);
void	draw_map2(t_game *game);
int		check_five_char(t_game *game);
int		parsing_map(t_game *game);
int		check_rectangularity(t_game *game);
int		one_player(t_game *game);
int		draw_player_supports(t_game *game);
void	init_imgs(t_game *game);
void	initialize(t_game *game, char *map_file);
int		check_vertical_walls(t_game *game);
int		check_horizontal_walls(t_game *game);
void	eaten_collect(t_game *game);
int		check_parsing(t_game *game);
int		clooose(t_game *game);
void	free_map(t_game *game);
void	free_imgs(t_game *game);
void	free_struct(t_game *game);
void	free_n_exit(t_game *game);
void	here(t_game *game);
int		check_wall(t_game *game, int x, int y);

#endif
