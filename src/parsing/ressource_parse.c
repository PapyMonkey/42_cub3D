/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressource_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:15:40 by bgales            #+#    #+#             */
/*   Updated: 2023/04/19 19:59:45 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_empty(t_game **game)
{
	if (!(*game)->floor)
		print_free_exit("Error\nFloor ressource is empty.\n", game);
	if (!(*game)->ceiling)
		print_free_exit("Error\nCeiling ressource is empty.\n", game);
	if (!(*game)->north)
		print_free_exit("Error\nNorth texture is empty.\n", game);
	if (!(*game)->south)
		print_free_exit("Error\nSouth texture is empty.\n", game);
	if (!(*game)->east)
		print_free_exit("Error\nEast texture is empty.\n", game);
	if (!(*game)->west)
		print_free_exit("Error\nWest texture is empty.\n", game);
}

void	get_rgb(t_game **game, int line)
{
	if (in_set("C", ((*game)->ressources[line][0])) && !(*game)->ceiling)
		(*game)->ceiling = ft_strdup((*game)->ressources[line]);
	if (in_set("F", ((*game)->ressources[line][0])) && !(*game)->floor)
		(*game)->floor = ft_strdup((*game)->ressources[line]);
}

void	get_texture(t_game **game, int line)
{
	if ((*game)->ressources[line][0] == 'N' && in_set("O",
		((*game)->ressources[line][1])) && !(*game)->north)
		(*game)->north = ft_strdup((*game)->ressources[line]);
	if ((*game)->ressources[line][0] == 'S' && in_set("O",
		((*game)->ressources[line][1])) && !(*game)->south)
		(*game)->south = ft_strdup((*game)->ressources[line]);
	if ((*game)->ressources[line][0] == 'W' && in_set("E",
		((*game)->ressources[line][1])) && !(*game)->west)
		(*game)->west = ft_strdup((*game)->ressources[line]);
	if ((*game)->ressources[line][0] == 'E' && in_set("A",
		((*game)->ressources[line][1])) && !(*game)->east)
		(*game)->east = ft_strdup((*game)->ressources[line]);
}

void	ressource_parse(t_game **game)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while ((*game)->ressources[++i])
	{
		if (in_set("CF", (*game)->ressources[i][j]))
			get_rgb(game, i);
		else if (in_set("NSWE", (*game)->ressources[i][j]))
			get_texture(game, i);
		else
			print_free_exit("Error\nWrong texture format.\n", game);
	}
	parse_ceiling(game, (*game)->ceiling);
	parse_floor(game, (*game)->floor);
	is_empty(game);
	parse_texture(game);
}
