/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:30:27 by bgales            #+#    #+#             */
/*   Updated: 2023/04/18 18:42:06 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	null_all(t_game **game)
{
	(*game)->north = NULL;
	(*game)->south = NULL;
	(*game)->east = NULL;
	(*game)->west = NULL;
	(*game)->ceiling = NULL;
	(*game)->floor = NULL;
}

int	in_set(char *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

void	is_cub(char *map_path)
{
	if (map_path[ft_strlen(map_path) - 4] != '.'
		|| map_path[ft_strlen(map_path) - 3] != 'c'
		|| map_path[ft_strlen(map_path) - 2] != 'u'
		|| map_path[ft_strlen(map_path) - 1] != 'b')
		print_and_exit("Error\nMap must be to \".cub\" format\n");
}

int	itter_whitespace(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] && (str[i] == ' ' || str[i] == '	' || str[i] == '\v'))
		;
	return (i);
}

int	itter_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}
