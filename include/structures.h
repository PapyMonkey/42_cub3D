/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:46:22 by bgales            #+#    #+#             */
/*   Updated: 2023/04/19 17:47:21 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_game{
	char	**map;
	char	**ressources;
	char	*floor;
	int		f_rgb[3];
	int		c_rgb[3];
	char	*ceiling;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_game;

#endif