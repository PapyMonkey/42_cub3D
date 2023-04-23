/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:10:15 by bgales            #+#    #+#             */
/*   Updated: 2023/04/23 14:34:59 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_game *game, int y, int x)
{
	double	x_draw;
	double	y_draw;

	x_draw = x;
	y_draw = y;
	while (y_draw < y + 1)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x * 32, y_draw * 32, 16711680);
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, (x + 1) * 32, y_draw * 32, 16711680);
		y_draw += 0.01;
	}
	while (x_draw < x + 1)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x_draw * 32, y * 32, 16711680);
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x_draw * 32, (y + 1) * 32, 16711680);
		x_draw += 0.01;
	}
}

void	draw_player(t_game *game, int i, int j)
{
	double	x;
	double	y;

	x = j - 0.1;
	y = i - 0.1;
	while ((x += 0.01) < j)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x * 32, i * 32, 16777011);
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x * 32, y * 32, 16777011);
	}
	x = j - 0.1;
	y = i - 0.1;
	while ((y += 0.01) < i)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, j * 32, y * 32, 16777011);
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x * 32, y * 32, 16777011);
	}

}

void	mini_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->map[++i])
	{
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				draw_map(game, i, j);
			if (in_set("NEWS", game->map[i][j]))
				draw_player(game, i, j);
		}
		j = -1;
	}
}
void	game_init(t_game **game)
{

	(*game)->mlx_ptr = mlx_init();
	(*game)->win_ptr = mlx_new_window((*game)->mlx_ptr,
		(((*game)->width - 1)) * 32, (((*game)->height) * 32), "cub3D");
	mini_map(*game);
	mlx_loop((*game)->mlx_ptr);
}