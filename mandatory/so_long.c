/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:14:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/17 04:33:18 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_game *game, int x, int y)
{
	if (game->mapy->arr[x][y] != '1')
	{
		game->tanjiro->count_moves += 1;
		ft_putnbr_fd(game->tanjiro->count_moves, 1);
		write (1, "\n", 1);
		return (1);
	}
	return (0);
}

void	try_harder(t_game *game, int a)
{
	free(game->tanjiro->move);
	if (a == 125)
	{
		if (check_wall(game, game->tanjiro->y / 75 + 1, game->tanjiro->x / 75))
			game->tanjiro->y += 75;
		game->tanjiro->move = ft_strdup("do");
	}
	if (a == 126)
	{
		if (check_wall(game, game->tanjiro->y / 75 - 1, game->tanjiro->x / 75))
			game->tanjiro->y -= 75;
		game->tanjiro->move = ft_strdup("up");
	}
	if (a == 123)
	{
		if (check_wall(game, game->tanjiro->y / 75, game->tanjiro->x / 75 - 1))
			game->tanjiro->x -= 75;
		game->tanjiro->move = ft_strdup("le");
	}
	if (a == 124)
	{
		if (check_wall(game, game->tanjiro->y / 75, game->tanjiro->x / 75 + 1))
			game->tanjiro->x += 75;
		game->tanjiro->move = ft_strdup("ri");
	}
}

int	try(int a, t_game *game)
{
	if (a == 53)
		exit (0);
	if (a == 123 || a == 124 || a == 125 || a == 126)
	{
		try_harder(game, a);
		eaten_collect(game);
		mlx_clear_window(game->mlx.mlx, game->mlx.mlx_win);
		game->img.img = mlx_new_image(game->mlx.mlx, \
			game->mapy->height, game->mapy->width);
		game->img.addr = mlx_get_data_addr(game->img.img, \
			&game->img.bits_per_pixel, &game->img.line_length, \
			&game->img.endian);
		draw_map2(game);
	}
	return (0);
}

int	clooose(t_game *game)
{
	free(game);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc == 2)
	{
		initialize(game, argv[1]);
		if (!check_parsing(game))
			exit (0);
		draw_map(game);
		mlx_hook(game->mlx.mlx_win, 2, 0, try, game);
		mlx_hook(game->mlx.mlx_win, 17, 1L << 5, clooose, game);
		mlx_loop(game->mlx.mlx);
	}
	free(game);
	return (0);
}
