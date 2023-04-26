/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgales <bgales@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:41:05 by bgales            #+#    #+#             */
/*   Updated: 2023/04/26 15:59:57 by bgales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// *****************************************************************************
// Functions - get_size.c

/*
@brief Calculates the number of lines in the file at the given path.

@param map_path The path to the map file.
@return Returns the number of lines in the file.
*/
int			brut_file_size(char *map_path);

/*
@brief Calculates the number of valid rows in the map array.

@param cub_file The map array to count.
@return Returns the number of valid rows in the map.
*/
int			coolsize(char **cub_file);

/*
@brief Calculates map's height and width.

@param game The game structure.
*/
void		get_xy(t_game **game);

// *****************************************************************************
// Functions - get_info.c

/*
@brief	Read the content of a map file and return it as an array of strings.

@param map_path   Path of the map file.
@return			Returns an array of strings containing the content of the map file.
*/
char		**get_file(char *map_path, t_game **game);

/*
@brief Extract the map section from the cub_file.

@param cub_file   An array of strings representing the cub file content.
@return 		Returns a new array of strings containing only the map section.
*/
char		**get_map(char **cub_file);

/*
@brief Extract the resources section from the cub_file.

@param cub_file		An array of strings representing the cub file content.
@return			Returns a new array of strings containing only the resources section.
*/
char		**get_ressources(char **cub_file, t_game **game);

// *****************************************************************************
// Functions - parse_utils.c

/*
@brief Set all pointers in the game structure to NULL.

@param game   Pointer to the game structure.
*/
void		null_all(t_game **game);

/*
@brief Check if the given character is in the provided set.

@param set   Set of characters to check.
@param c     Character to search for.
@return      Returns 1 if the character is in the set, otherwise 0.
*/
int			in_set(char *set, char c);

/*
@brief Check if the map file has a ".cub" extension.

@param map_path   Path of the map file.
*/
void		is_cub(char *map_path, t_game **game);

// *****************************************************************************
// Functions - iteration_utils.c

/*
@brief Iterate through whitespace characters in the given string.

@param str   The input string.
@return      Returns the index of the first non-whitespace character.
*/
int			iter_whitespace(char *str);

/*
@brief Iterate through digits in the given string.

@param str   The input string.
@return      Returns the index of the first non-digit character.
*/
int			iter_digit(char *str);

/*
@brief Iterate through wall characters (1) in the given string.

@param str   The input string.
@return      Returns the index of the first non-wall character.
*/
int			iter_walls(char *str);

/*
@brief Iterate through space characters in the given string.

@param str   The input string.
@return      Returns the index of the first non-space character.
*/
int			iter_space(char *str);

/*
@brief Iterate through characters in the given string until a space, tab,
       vertical tab, or newline character is encountered.

@param str   The input string.
@return      Returns the index of the first space, tab, vertical tab, or
             newline character.
*/
int			iter_no_spaceornl(char *str);

// *****************************************************************************
// Functions - free.c

/*
@brief Print the given string and exit the program.
@param str The string to be printed.
@param game The game structure to be freed.
*/
void		print_free_exit(char *str, t_game **game);

/*
@brief Frees char array.
@param tab The array to be freed.
*/
void		free_char_array(char **tab);

/*
@brief Frees all elements of the given game structure.
@param game The game struct to be freed
*/
void		free_struct(t_game **game);

#endif