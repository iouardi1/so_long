/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:14:43 by iouardi           #+#    #+#             */
/*   Updated: 2022/02/17 12:07:13 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include "here/libft.h"
#include "heeere/get_next_line.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	draw_square(int i, int j, int color, t_data *img)
// {
// 	int		x;
// 	int		y;

// 	x = j * 100;
// 	while (x < (j + 1) * 100)
// 	{
// 		y = i * 100;
// 		while (y < (i + 1) * 100)	
// 			my_mlx_pixel_put(img, x, y++, color);
// 		x++;
// 	}
// }
void 	draw_map(char **arr,void *color, void *mlx, void *mlx_win)
{
	int		i = 0;
	int		j;
	int		x = 0;
	int		y = 0;
	int		width = 75;
	int		height = 75;
	//char	*path = "./nizku.xpm";
	
	while (arr[i])
	{
		j = 0;
		x = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '1')
			{
				color = mlx_xpm_file_to_image(mlx_win, "wall.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, color, x,  y);
			}
			else if (arr[i][j] == 'C')
			{
				color = mlx_xpm_file_to_image(mlx_win,"nizku75.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, color, x, y);
			}
			else if (arr[i][j] == 'E')
			{
				color = mlx_xpm_file_to_image(mlx_win, "frontlook_tanjiro75.xpm", &width, &height);
				mlx_put_image_to_window(mlx, mlx_win, color, x, y);
			}
			x += 75;
			j++;
		}
		y += 75;
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*tab;
	char	*trr;
	char	**arr;
	int		fd = open("my_map.ber", O_RDONLY);
	char	*relative_path = "./nizku75.xpm";
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	tab = get_next_line(fd);
	trr = NULL;

	while (tab)
	{
		trr = ft_strjoin(trr, tab);
		tab = get_next_line(fd);
	}
	arr = ft_split(trr, '\n');
	mlx = mlx_init();
	i = 0;
	while (arr[i])
	{
		j = 0;
		while(arr[i][j])
			j++;
		i++;
	}
	i *= 75;
	j *= 75;
	mlx_win = mlx_new_window(mlx, j, i, "Hello khames!");
	img.img = mlx_new_image(mlx, 3000, 3000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//i = 0;
	void *color = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	draw_map(arr, color, mlx, mlx_win);
	mlx_loop(mlx);
}
