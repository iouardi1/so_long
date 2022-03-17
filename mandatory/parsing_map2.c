/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:18:53 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/14 16:18:45 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	one_player(t_game *game)
{
	int		x;
	int		y;
	int		compt;

	compt = 0;
	x = 0;
	while (game->mapy->arr[x])
	{
		y = 0;
		while (game->mapy->arr[x][y])
		{
			if (game->mapy->arr[x][y] == 'P')
				compt++;
			y++;
		}
		x++;
	}
	if (compt != 1)
		return (0);
	return (1);
}

int	check_vertical_walls(t_game *game)
{
	int		x;
	int		j;

	x = ft_strlen(game->mapy->arr[0]) - 1;
	j = 0;
	while (game->mapy->arr[j])
	{
		if (game->mapy->arr[j][0] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (game->mapy->arr[j])
	{
		if (game->mapy->arr[j][x] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_horizontal_walls(t_game *game)
{
	int		y;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (game->mapy->arr[i])
		i++;
	y = i - 1;
	while (game->mapy->arr[0][j])
	{
		if (game->mapy->arr[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (game->mapy->arr[y][j])
	{
		if (game->mapy->arr[y][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
