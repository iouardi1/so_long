/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:23:13 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/17 04:32:22 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_player_supports(t_game *game)
{
	if (!ft_strncmp(game->tanjiro->move, "do", 3))
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
			game->mapy->player_up, game->tanjiro->x, game->tanjiro->y);
		return (0);
	}
	else if (!ft_strncmp(game->tanjiro->move, "up", 3))
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
			game->mapy->player_down, game->tanjiro->x, game->tanjiro->y);
		return (0);
	}
	return (1);
}

void	draw_player(t_game *game)
{
	if (draw_player_supports(game))
	{
		if (!ft_strncmp(game->tanjiro->move, "ri", 3))
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->mapy->player_right, game->tanjiro->x, game->tanjiro->y);
		else if (!ft_strncmp(game->tanjiro->move, "le", 3))
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->mapy->player_left, game->tanjiro->x, game->tanjiro->y);
	}
}

void	eaten_collect(t_game *game)
{
	if (game->mapy->arr[(game->tanjiro->y / 75)] \
		[(game->tanjiro->x / 75)] == 'C')
	{
		game->mapy->arr[(game->tanjiro->y / 75)][(game->tanjiro->x / 75)] = '0';
		game->tanjiro->eaten_collect++;
	}
	if (game->tanjiro->eaten_collect == game->mapy->collects && \
		game->mapy->arr[(game->tanjiro->y / 75)] \
			[(game->tanjiro->x / 75)] == 'E')
		exit (0);
}
