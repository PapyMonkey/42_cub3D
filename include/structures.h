/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:46:22 by bgales            #+#    #+#             */
/*   Updated: 2023/04/21 15:02:36 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_game{
	void	*mlx_ptr;
	void	*win_ptr;
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
	int		height;
	int		width;
}	t_game;

#endif