/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:32:00 by bgales            #+#    #+#             */
/*   Updated: 2023/04/18 18:37:00 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_parse(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		j += itter_whitespace(&map[i][j]);
		if (map[i][j] != '1')
			print_and_exit("Error\nWrong map format.\n");
		while (map[i][j])
		{
			if (in_set("10NEWS", map[i][j]))
				j++;
			else if (!map[i][j] || map[i][j] == '\n')
			{
				if (map[i][j - 1] != '1')
					print_and_exit("Error\nWrong map format.\n");
				break ;
			}
			else
				print_and_exit("Error\nWrong map format.\n");
		}
		j = 0;
	}
}
