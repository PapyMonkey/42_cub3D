/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:22:07 by bgales            #+#    #+#             */
/*   Updated: 2023/04/20 11:45:12 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_color(int *rgb, int j, t_game **game)
{
	if (j != 3)
		print_free_exit("Error\n Wrong color format", game);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0
		|| rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
		print_free_exit("Error\n Wrong color format", game);
}

void	parse_ceiling(t_game **game, char *str)
{
	int		i;
	int		j;
	char	*color;

	i = 0;
	j = 0;
	while (str[++i])
	{
		i += iter_whitespace(&str[i]);
		if (str[i] >= '0' && str[i] <= '9')
		{
			color = ft_substr(&str[i], 0, iter_digit(&str[i]));
			i += iter_digit(&str[i]);
			i += iter_whitespace(&str[i]);
			(*game)->c_rgb[j++] = ft_atoi(color);
			free(color);
		}
		else
			print_free_exit("Error\n Wrong color format", game);
	}
	parse_color((*game)->c_rgb, j, game);
}

void	parse_floor(t_game **game, char *str)
{
	int		i;
	int		j;
	char	*color;

	i = 0;
	j = 0;
	while (str[++i])
	{
		i += iter_whitespace(&str[i]);
		if (str[i] >= '0' && str[i] <= '9')
		{
			color = ft_substr(&str[i], 0, iter_digit(&str[i]));
			i += iter_digit(&str[i]);
			i += iter_whitespace(&str[i]);
			(*game)->f_rgb[j++] = ft_atoi(color);
			free(color);
		}
		else
			print_free_exit("Error\n Wrong color format", game);
	}
	parse_color((*game)->f_rgb, j, game);
}
