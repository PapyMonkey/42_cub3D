/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:40:57 by bgales            #+#    #+#             */
/*   Updated: 2023/04/19 18:32:59 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	brut_file_size(char *map_path)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(map_path, O_RDONLY);
	ret = 0;
	while (1)
	{
		line = get_next_line(fd);
		ret++;
		if (!line)
			break ;
		free (line);
	}
	close(fd);
	return (ret);
}

int	coolsize(char **cub_file)
{
	int	i;
	int	c;
	int	j;

	i = -1;
	c = 0;
	j = 0;
	while (cub_file[++i])
	{
		j += iter_whitespace(cub_file[i]);
		if (cub_file[i][j] == '\0' || cub_file[i][j] == '\n')
			j = 0;
		else
		{
			c++;
			j = 0;
		}
	}
	return (c);
}