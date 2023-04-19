/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:09:56 by bgales            #+#    #+#             */
/*   Updated: 2023/04/19 19:28:15 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	player_parser(char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = -1;
	j = -1;
	player_count = 0;
	while (map[++i])
		if (in_set("NEWS", map[i][0]) || in_set("NEWS", map[i][ft_strlen(map[i])]))
			print_and_exit("Error\nPlayer's on the edge of the map.\n");
	i = -1;
	while (map[++i])
	{
		while(map[i][++j])
			if (in_set("NEWS", map[i][j]))
			{
				player_count++;
				is_surrounded(map, i, j);
			}
		j = 0;
	}
	if (player_count != 1)
		print_and_exit("Error\nOne player is expected.\n");
}