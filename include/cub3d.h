/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:19:22 by bgales            #+#    #+#             */
/*   Updated: 2023/04/20 11:38:35 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

// *****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"
# include "parse.h"
# include "utils.h"

char	*get_next_line(int fd);
// *****************************************************************************
// Functions - main.c

/*
@brief Remove empty lines from the input cub_file.

@param cub_file   An array of strings representing the cub file content.
@return           Returns a new array of strings without the empty lines.
*/
char	**del_empty_lines(char **cub_file);

/*
@brief	Read the content of a map file and return it as an array of strings.

@param map_path   Path of the map file.
@return			Returns an array of strings containing the content of the map file.
*/
char	**get_file(char *map_path, t_game **game);

/*
@brief Extract the map section from the cub_file.

@param cub_file   An array of strings representing the cub file content.
@return 		Returns a new array of strings containing only the map section.
*/
char	**get_map(char **cub_file);

/*
@brief Extract the resources section from the cub_file.

@param cub_file		An array of strings representing the cub file content.
@return			Returns a new array of strings containing only the resources section.
*/
char	**get_ressources(char **cub_file, t_game **game);

#endif