/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:36:56 by rafnasci          #+#    #+#             */
/*   Updated: 2023/11/24 15:53:37 by rafnasci         ###   ########.fr       */
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
	int	p_x;
	int	p_y;
}	t_map;

int		ft_checkfile(char *file);
int		ft_checkmap(char *file, t_map *map);
int		ft_checkline(char *line, t_map *map);
int		ft_checkborders(char *line, t_map *map);
void	ft_initmap(t_map *map, char *line);
int		ft_checkpath(char *file, t_map *map);
int		ft_backtrack(int x, int y, t_map *map, char **plan);
void	ft_initmap(t_map *map, char *line);
int		ft_checkborders(char *line, t_map *map);
int		ft_findplayer(char **plan, t_map *map);
int		main(int argc, char **argv);

#endif