/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:32:44 by bgales            #+#    #+#             */
/*   Updated: 2023/04/18 18:38:30 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_north_south(char *str)
{
	int		i;
	int		j;
	int		fd;
	char	*tmp;

	i = 1;
	if (str[i++] != 'O')
		print_and_exit("Error\nWrong texture format.\n");
	i += itter_whitespace(&str[i]);
	j = itter_no_spaceornl(&str[i]);
	tmp = ft_substr(&str[i], 0, j);
	i += j;
	i += itter_whitespace(&str[i]) + 1;
	if (str[i] != '\0')
		print_and_exit("Error\nTexture couldnt be loaded.\n");
	if (open(tmp, O_RDONLY) < 0)
		print_and_exit("Error\nTexture couldnt be loaded.\n");
	close(fd);
}

void	parse_east(char *str)
{
	int		i;
	int		j;
	int		fd;
	char	*tmp;

	i = 1;
	if (str[i++] != 'A')
		print_and_exit("Error\nWrong texture format.\n");
	i += itter_whitespace(&str[i]);
	j = itter_no_spaceornl(&str[i]);
	tmp = ft_substr(&str[i], 0, j);
	i += j;
	i += itter_whitespace(&str[i]) + 1;
	if (str[i] != '\0')
		print_and_exit("Error\nTexture couldnt be loaded.\n");
	if (open(tmp, O_RDONLY) < 0)
		print_and_exit("Error\nTexture couldnt be loaded.\n");
	close(fd);
}

void	parse_west(char *str)
{
	int		i;
	int		j;
	int		fd;
	char	*tmp;

	i = 1;
	if (str[i++] != 'E')
		print_and_exit("Error\nWrong texture format.\n");
	i += itter_whitespace(&str[i]);
	j = itter_no_spaceornl(&str[i]);
	tmp = ft_substr(&str[i], 0, j);
	i += j;
	i += itter_whitespace(&str[i]) + 1;
	if (str[i] != '\0')
		print_and_exit("Error\nTexture couldnt be loaded.\n");
	if (open(tmp, O_RDONLY) < 0)
		print_and_exit("Error\nTexture couldnt be loaded.\n");
	close(fd);
}

void	parse_texture(t_game **game)
{
	parse_north_south((*game)->north);
	parse_north_south((*game)->south);
	parse_east((*game)->east);
	parse_west((*game)->west);
}
