/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:39:33 by bgales            #+#    #+#             */
/*   Updated: 2023/04/17 16:32:40 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**del_empty_lines(char **cub_file)
{
	int	i;
	int	j;
	int	c;
	char **ret;

	i = -1;
	j = 0;
	c = 0;
	ret = malloc(sizeof(char *) * (clean_file_size(cub_file) + 1));
	while(cub_file[++i] && c < clean_file_size(cub_file))
	{
		j += itter_whitespace(cub_file[i]);
		if (cub_file[i][j] && (cub_file[i][j] == '\0' || cub_file[i][j] == '\n') && c <= 6)
			j = 0;
		else
		{
			if (c < 6)
				ret[c] = ft_substr(cub_file[i], j, ft_strlen(cub_file[i]));
			else
					ret[c] = ft_substr(cub_file[i], 0, ft_strlen(cub_file[i]));
			c++;
			j = 0;
		}
	}
	ret[c] = NULL;
	return (ret);
}

char	**get_file(char *map_path)
{
	int		fd;
	char	**ret;
	int		i;

	is_cub(map_path);
	ret = malloc(sizeof(char *) * (brut_file_size(map_path) + 1));
	fd = open(map_path, O_RDONLY);
	i = 0;
	while ((ret[i] = get_next_line(fd)))
		i++;
	close(fd);
	i = -1;
	ret = del_empty_lines(ret);
	return (ret);
}

char	**get_map(char **cub_file)
{
	int		i;
	int		j;
	char	**ret;

	i = 6;
	j = 0;
	while(cub_file[i])
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

char	**get_ressources(char **cub_file)
{
	int		i;
	int		j;
	char	**ret;

	ret = malloc(sizeof(char *) * 7);
	i = -1;
	j = 0;
	while(++i < 6)
	{
		j += itter_whitespace(cub_file[i]);
		ret[i] = ft_substr(cub_file[i], j, ft_strlen(cub_file[i]));
		j = 0;
	}
	j += itter_whitespace(cub_file[i]);
	if (cub_file[i][j] != '1')
		print_and_exit("Error\n map file uncorrectly formated.\n");
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
	cub_file = get_file(argv[1]);
	NULL_all(&game);
	game->map = get_map(cub_file);
	game->ressources = get_ressources(cub_file);
	ressource_parse(&game);
	map_parse(game->map);
	// system("leaks cub3d");
}