/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:23:26 by bgales            #+#    #+#             */
/*   Updated: 2023/04/19 15:19:25 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	itter_walls(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] == '1')
		i++;
	return (i);
}

int	itter_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	itter_no_spaceornl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '	'
			&& str[i] != '\v' && str[i] != '\n'))
		i++;
	return (i);
}
