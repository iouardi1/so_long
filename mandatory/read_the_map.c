/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:12:13 by iouardi           #+#    #+#             */
/*   Updated: 2022/03/17 01:35:30 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_the_map(t_game *game, int fd)
{
	char	*tab;
	char	*temp;
	char	*temp2;

	temp = NULL;
	tab = get_next_line(fd);
	while (tab)
	{
		temp2 = temp;
		temp = ft_strjoin(temp, tab);
		free (tab);
		free (temp2);
		tab = get_next_line(fd);
		if (tab == NULL)
			break ;
		if (ft_strlen(tab) == 1)
		{
			write (1, "map invalid a 3chiri!\n", 23);
			exit (0);
		}
	}
	game->mapy->arr = ft_split(temp, '\n');
	free (temp);
}
