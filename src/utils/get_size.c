/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:40:57 by bgales            #+#    #+#             */
/*   Updated: 2023/04/13 16:42:31 by bgales           ###   ########.fr       */
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
	while ((line = get_next_line(fd)))
	{
		ret++;
		free (line);
	}
	close(fd);
	return (ret);
}

int	clean_file_size(char **cub_file)
{
	int	i;
	int	c;
	int	j;

	i = -1;
	c = 0;
	j = 0;
	while(cub_file[++i])
	{
		j += itter_whitespace(cub_file[i]);
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
