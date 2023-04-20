/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:42:32 by bgales            #+#    #+#             */
/*   Updated: 2023/04/20 12:31:18 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_struct(t_game **game)
{
	int	i;

	i = -1;
	while ((*game)->map[++i])
		free((*game)->map[i]);
	free ((*game)->map);
	i = -1;
	while ((*game)->ressources[++i])
		free((*game)->ressources[i]);
	free ((*game)->ressources);
	free((*game)->floor);
	free((*game)->ceiling);
	free((*game)->north);
	free((*game)->west);
	free((*game)->east);
	free((*game)->south);
	free (*game);
}

void	free_char_array(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free (tab);
}

void	print_free_exit(char *str, t_game **game)
{
	if (str)
		printf("%s", str);
	free_struct(game);
	exit (0);
}
