/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:19:22 by bgales            #+#    #+#             */
/*   Updated: 2023/04/21 12:39:51 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

// *****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"
# include "parse.h"
# include "utils.h"
# include "game.h"

char	*get_next_line(int fd);
// *****************************************************************************
// Functions - main.c

/*
@brief Remove empty lines from the input cub_file.

@param cub_file   An array of strings representing the cub file content.
@return           Returns a new array of strings without the empty lines.
*/
char	**del_empty_lines(char **cub_file);



#endif