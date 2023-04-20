/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:39:33 by bgales            #+#    #+#             */
/*   Updated: 2023/04/20 11:44:22 by bgales           ###   ########.fr       */
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
	free_2d_char(file);
	return (ret);
}

char	**get_file(char *map_path, t_game **game)
{
	int		fd;
	char	**ret;
	int		i;

	is_cub(map_path, game);
	ret = malloc(sizeof(char *) * (brut_file_size(map_path) + 1));
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		print_free_exit("Error\nMap file was not found.\n", game);
	i = 0;
	while (1)
	{
		ret[i] = get_next_line(fd);
		if (!ret[i])
			break ;
		i++;
	}
	close(fd);
	ret = del_empty_lines(ret);
	i = 0;
	while (ret[i])
		i++;
	if (i <= 6)
		print_free_exit("Error\nMap file is incomplete.\n", game);
	return (ret);
}

char	**get_map(char **cub_file)
{
	int		i;
	int		j;
	char	**ret;

	i = 6;
	j = 0;
	while (cub_file[i])
	{
		i++;
		j++;
	}
	ret = malloc(sizeof(char *) * (j + 1));
	i = 6;
	j = 0;
	while (cub_file[i])
		ret[j++] = ft_strdup(cub_file[i++]);
	ret[j] = NULL;
	return (ret);
}

char	**get_ressources(char **cub_file, t_game **game)
{
	int		i;
	int		j;
	char	**ret;

	ret = malloc(sizeof(char *) * 7);
	i = -1;
	j = 0;
	while (++i < 6)
	{
		j += iter_whitespace(cub_file[i]);
		ret[i] = ft_substr(cub_file[i], j, ft_strlen(cub_file[i]));
		j = 0;
	}
	j += iter_whitespace(cub_file[i]);
	if (cub_file[i][j] != '1')
	{
		free_2d_char(cub_file);
		print_free_exit("Error\n map file uncorrectly formated.\n", game);
	}
	ret[i] = NULL;
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
	null_all(&game);
	cub_file = get_file(argv[1], &game);
	game->map = get_map(cub_file);
	game->ressources = get_ressources(cub_file, &game);
	free_2d_char(cub_file);
	ressource_parse(&game);
	map_parser(game->map, &game);
	player_parser(game->map, &game);
	print_free_exit(NULL, &game);
}
