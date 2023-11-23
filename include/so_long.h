/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:36:56 by rafnasci          #+#    #+#             */
/*   Updated: 2023/11/23 13:35:57 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_map
{
	int	height;
	int	width;
	int	collectible;
	int	exit;
	int	player;
	int	last_border;
	int	borders;
}	t_map;

int		ft_checkfile(char *file);
int		ft_checkmap(char *file, t_map *map);
int		ft_checkline(char *line, t_map *map);
int		main(int argc, char **argv);

#endif