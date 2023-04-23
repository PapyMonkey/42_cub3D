/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:39:33 by bgales            #+#    #+#             */
/*   Updated: 2023/04/21 13:44:20 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**del_empty_lines(char **file)
{
	int		i;
	int		j;
	int		c;
	char	**ret;

	i = -1;
	ret = malloc(sizeof(char *) * (coolsize(file) + 1) + (j = 0) + (c = 0));
	while (file[++i] && c < coolsize(file))
	{
		j += iter_whitespace(file[i]);
		if (file[i][j] && (file[i][j] == '\0' || file[i][j] == '\n') && c <= 6)
			j = 0;
		else
		{
			if (c < 6)
				ret[c] = ft_substr(file[i], j, ft_strlen(file[i]));
			else
					ret[c] = ft_substr(file[i], 0, ft_strlen(file[i]));
			c++;
			j = 0;
		}
	}
	ret[c] = NULL;
	free_char_array(file);
	return (ret);
}



int	main(int argc, char **argv)
{
	t_game	*game;
	char	**cub_file;

	game = malloc(sizeof(t_game));
	if (argc != 2)
	{
		printf("Wrong argument format");
		exit (0);
	}
	parser(&game, cub_file, argv[1]);
	game_init(&game);
}