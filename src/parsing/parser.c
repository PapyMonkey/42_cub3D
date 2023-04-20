/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:20:59 by bgales            #+#    #+#             */
/*   Updated: 2023/04/20 12:38:19 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(t_game **game, char **cub_file, char *map_path)
{
	null_all(game);
	cub_file = get_file(map_path, game);
	(*game)->map = get_map(cub_file);
	(*game)->ressources = get_ressources(cub_file, game);
	free_char_array(cub_file);
	ressource_parse(game);
	map_parser((*game)->map, game);
	player_parser((*game)->map, game);
	print_free_exit(NULL, game);
}
