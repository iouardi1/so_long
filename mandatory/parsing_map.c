/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:27:07 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/16 20:28:07 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_one_char(char **arr, char c)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (ft_strchr(arr[i], c))
			return (1);
		i++;
	}
	return (0);
}

int	check_three_char(t_game *game)
{
	int		compt_char;

	compt_char = 0;
	if (check_one_char(game->mapy->arr, 'E'))
		compt_char++;
	if (check_one_char(game->mapy->arr, 'C'))
		compt_char++;
	if (check_one_char(game->mapy->arr, 'P'))
		compt_char++;
	if (compt_char == 3)
		return (3);
	return (0);
}

int	check_strange_char(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	while (game->mapy->arr[x])
	{
		y = 0;
		while (game->mapy->arr[x][y])
		{
			if (game->mapy->arr[x][y] != '1' && game->mapy->arr[x][y] != '0' \
				&& game->mapy->arr[x][y] != 'C' && game->mapy->arr[x][y] != 'P' \
				&& game->mapy->arr[x][y] != 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	check_rectangularity(t_game *game)
{
	int		x;
	size_t	len;

	x = 1;
	len = ft_strlen(game->mapy->arr[0]);
	while (game->mapy->arr[x])
	{
		if (ft_strlen(game->mapy->arr[x]) != len)
			return (0);
		x++;
	}
	return (1);
}

int	parsing_map(t_game *game)
{
	if (!game->mapy->arr)
		return (0);
	if (!check_three_char(game))
		return (0);
	if (!check_strange_char(game))
		return (0);
	if (!check_rectangularity(game))
		return (0);
	if (!one_player(game))
		return (0);
	if (!check_horizontal_walls(game))
		return (0);
	if (!check_vertical_walls(game))
		return (0);
	return (1);
}
