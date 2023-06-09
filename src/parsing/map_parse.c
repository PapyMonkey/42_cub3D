/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:32:00 by bgales            #+#    #+#             */
/*   Updated: 2023/04/20 11:46:41 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_surrounded(char **map, int line, int index, t_game **game)
{
	if (ft_strlen(map[line - 1]) < index)
		print_free_exit("Error\nAn element must be surrounded by walls.\n", game);
	if (ft_strlen(map[line + 1]) < index)
		print_free_exit("Error\nAn element must be surrounded by walls.\n", game);
	if (!in_set("10NEWS", map[line + 1][index]))
		print_free_exit("Error\nAn element must be surrounded by walls.\n", game);
	if (!in_set("10NEWS", map[line - 1][index]))
		print_free_exit("Error\nAn element must be surrounded by walls.\n", game);
	if (!in_set("10NEWS", map[line][index - 1]))
		print_free_exit("Error\nAn element must be surrounded by walls.\n", game);
	if (!in_set("10NEWS", map[line][index + 1]))
		print_free_exit("Error\nAn element must be surrounded by walls.\n", game);
}

void	is_attached(char **map, int line, int index, t_game **game)
{
	while (map[line][index])
	{
		if (line != 0)
			if (ft_strlen(map[line - 1]) > index)
				if (in_set("10NEWS", map[line - 1][index]))
					break ;
		if (map[line + 1] != NULL)
			if (ft_strlen(map[line + 1]) > index)
				if (in_set("10NEWS", map[line + 1][index]))
					break ;
		index++;
	}
	if (!map[line][index])
		print_free_exit("Error\nMap must be of one block\n", game);
}

void	room_parse(char **map, t_game **game)
{
	int	line;
	int	index;

	line = -1;
	index = -1;
	while (map[++line])
	{
		while (map[line][++index])
			if (map[line][index] == '0')
				is_surrounded(map, line, index, game);
		index = -1;
	}
}

void	wall_parse(char **map, t_game **game)
{
	int	line;
	int	index;

	line = -1;
	index = 0;
	while (map[++line])
	{
		while (map[line][index])
		{
			if (map[line][index] == '1')
			{
				is_attached(map, line, index, game);
				index += iter_walls(&map[line][index]);
				index += iter_space(&map[line][index]);
			}
			else
				index++;
		}
		index = 0;
	}
}

void	map_parser(char **map, t_game **game)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		j += iter_space(&map[i][j]);
		if (map[i][j] != '1')
			print_free_exit("Error\nWrong map format.\n", game);
		while (in_set("10NEWS ", map[i][j++]))
		{
			if (!map[i][j] || map[i][j] == '\n')
			{
				if (map[i][j - 1] != '1' && map[i][j - 1] != ' ')
					print_free_exit("Error\nWrong map format.\n", game);
				break ;
			}
			if (!in_set("10NEWS ", map[i][j]))
				print_free_exit("Error\nWrong map format.\n", game);
		}
		j = 0;
	}
	room_parse(map, game);
	wall_parse(map, game);
}