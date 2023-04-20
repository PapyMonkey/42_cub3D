/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:43:14 by bgales            #+#    #+#             */
/*   Updated: 2023/04/20 12:38:35 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

// *****************************************************************************
// Personal library

# include "libft.h"
# include "structures.h"

// *****************************************************************************
// Functions - parser.c
/*
@brief The gate to all the other parsing functions.
@param game		The game structure.
@param cub_file	An array of strings representing the cub file content.
@param map_path A string containing the path to ".cub" file.

*/
void		parser(t_game **game, char **cub_file, char *map_path);

// *****************************************************************************
// Functions - color_parse.c
/*
@brief Parse a RGB color array and validate the format.
@param rgb An array containing the RGB color values.
@param j The size of the array.
*/
void		parse_color(int *rgb, int j, t_game **game);

/*
@brief Parse the ceiling color and store it in the game structure.
@param game The main game structure.
@param str The string containing the ceiling color.
*/
void		parse_ceiling(t_game **game, char *str);

/*
@brief Parse the floor color and store it in the game structure.
@param game The main game structure.
@param str The string containing the floor color.

*/
void		parse_floor(t_game **game, char *str);

// *****************************************************************************
// Functions - map_parse.c

/**
@brief Check if an element is surrounded by walls.

@param map The map to parse.
@param line The line index of the element to check.
@param index The index of the element to check.
@return None.
*/
void		is_surrounded(char **map, int line, int index, t_game **game);

/**
@brief Check if all elements of the map are tied together.

@param map The map to parse.
@param line The line index of the element to check.
@param index The index of the the element to check.
@return None.
*/
void		is_attached(char **map, int line, int index, t_game **game);

/**
@brief Parse the rooms in the map.

@param map The map to parse.
*/
void		room_parse(char **map, t_game **game);

/**
@brief Parse the walls in the map.

@param map The map to parse.
*/
void		wall_parse(char **map, t_game **game);

/**
@brief Parse the entire map.

@param map The map to parse.
*/
void		map_parser(char **map, t_game **game);

// *****************************************************************************
// Functions - ressource_parse.c

/**
@brief Check if any of the game resources is empty and exits if true.
@param game The game structure.
*/
void		is_empty(t_game **game);
/*

@brief Gets the RGB values from the game resources and stores them
in the game structure.
@param game The game structure.
@param line The index of the line containing the RGB values.
*/
void		get_rgb(t_game **game, int line);
/*

@brief Gets the texture paths from the game resources and stores them
 in the game structure.
@param game The game structure.
@param line The index of the line containing the texture path.
*/
void		get_texture(t_game **game, int line);
/**

@brief Parses the game resources and stores them
 in the game structure.
@param game The game structure.
*/
void		ressource_parse(t_game **game);

// *****************************************************************************
// Functions - ressource_parse.c

void		parse_north_south(char *str, t_game **game);
void		parse_east(char *str, t_game **game);
void		parse_west(char *str, t_game **game);
/*

@brief Parse all four textures (north, south, east, west)
from the game structure.
@param game The game structure to parse the textures from.
@return void.
*/
void		parse_texture(t_game **game);

// *****************************************************************************
// Functions - player_parse.c
/**
@brief Parse player position and number in the map
@param map The map to parse
*/
void		player_parser(char **map, t_game **game);

#endif