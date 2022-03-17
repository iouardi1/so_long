/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_check_parsing.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:14:37 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/17 04:32:51 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	link_pictures(t_game *game)
{
	int		height_tile;
	int		width_tile;

	game->mapy->wall = mlx_xpm_file_to_image(game->mlx.mlx, \
		"mandatory/images_xpm/wall.xpm", &width_tile, &height_tile);
	game->mapy->collect = mlx_xpm_file_to_image(game->mlx.mlx, \
		"mandatory/images_xpm/nizku75.xpm", &width_tile, &height_tile);
	game->mapy->exit = mlx_xpm_file_to_image(game->mlx.mlx, \
		"mandatory/images_xpm/nizku_box.xpm", &width_tile, &height_tile);
	game->mapy->player_up = mlx_xpm_file_to_image(game->mlx.mlx, \
		"mandatory/images_xpm/frontlook.xpm", &width_tile, &height_tile);
	game->mapy->player_right = mlx_xpm_file_to_image(game->mlx.mlx, \
		"mandatory/images_xpm/rightlook.xpm", &width_tile, &height_tile);
	game->mapy->player_left = mlx_xpm_file_to_image(game->mlx.mlx, \
		"mandatory/images_xpm/leftlook.xpm", &width_tile, &height_tile);
	game->mapy->player_down = mlx_xpm_file_to_image(game->mlx.mlx, \
		"mandatory/images_xpm/backlook.xpm", &width_tile, &height_tile);
}

void	initialize(t_game *game, char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	game->mapy = malloc(sizeof(t_mapy));
	game->tanjiro = malloc(sizeof(t_player));
	game->tanjiro->move = malloc(sizeof(char) * 3);
	read_the_map(game, fd);
	game->mlx.mlx = mlx_init();
	game->mapy->h_ntiles = 0;
	game->tanjiro->eaten_collect = 0;
	game->tanjiro->count_moves = 0;
}

int	check_parsing(t_game *game)
{
	if (!parsing_map(game))
	{
		printf("this map is invalid asat!\n");
		return (0);
	}
	link_pictures(game);
	while (game->mapy->arr[game->mapy->h_ntiles])
		game->mapy->h_ntiles++;
	game->mapy->v_ntiles = ft_strlen(game->mapy->arr[0]);
	game->mapy->height = game->mapy->v_ntiles * 75;
	game->mapy->width = game->mapy->h_ntiles * 75;
	return (1);
}
