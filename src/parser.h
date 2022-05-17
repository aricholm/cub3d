/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:03:44 by aricholm          #+#    #+#             */
/*   Updated: 2022/05/09 15:24:39 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "cub3d.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 10


void	parser(t_cub3d *cub3d, const char *file);
t_bool	add_texture(t_textures *textures, const char *line);
//char	*get_next_line(int fd);
//char	**get_lines(int fd);
#endif /* PARSER_H */
