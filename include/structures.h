/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:46:22 by bgales            #+#    #+#             */
/*   Updated: 2023/04/26 15:08:51 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

enum e_keycode
{
	A_KEY,
	S_KEY,
	D_KEY,
	W_KEY = 13,
	SPACE = 49,
	ECHAP = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT,
	ARROW_DOWN,
	ARROW_UP
};

typedef struct s_player{
	float	x;
	float	y;
	float	pdx;
	float	pdy;
	float	pa;
}	t_player;

typedef struct s_game{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		**ressources;
	char		*floor;
	int			f_rgb[3];
	int			c_rgb[3];
	char		*ceiling;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			height;
	int			width;
	t_player	*player;
}	t_game;

#endif