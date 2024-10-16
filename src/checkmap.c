/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:26:13 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/20 15:40:14 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_checkborders(char *line, t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
	{
		if (line[i] != '1')
		{
			if (map->height == 0)
				return (1);
			else
				return (0);
		}
	}
	if (map->height == 0)
		return (0);
	map->last_border = map->height + 1;
	return (0);
}

void	ft_initmap(t_map *map, char *line, t_state *state)
{
	map->width = ft_strlen(line);
	map->height = 0;
	map->collectible = 0;
	map->coll_isok = 0;
	map->exit = 0;
	map->player = 0;
	map->borders = 0;
	map->p_pos[0] = -1;
	map->p_pos[1] = -1;
	state->collected = 0;
	state->completed = 0;
	state->moves = 0;
	state->loop = 0;
	state->img_col = 0;
	state->img_col2 = 0;
}

int	ft_checkline(char *line, t_map *map)
{
	int	i;
	int	check;

	if (ft_checkborders(line, map)
		|| ((int)(ft_strlen(line)) != map->width)
		|| (line[0] != '1' || line[map->width - 1] != '1'))
		return (0);
	i = -1;
	check = 0;
	while (++i < map->width)
	{
		if (line[i] == 'C')
			map->collectible += 1;
		else if (line[i] == 'E')
			map->exit += 1;
		else if (line[i] == 'P')
			map->player += 1;
		else if (line[i] == '1')
			check++;
		else if (line[i] != '0')
			return (0);
	}
	if (check == map->width)
		map->borders += 1;
	return (1);
}

int	ft_checkmap(char *file, t_map *map, t_state *state)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nFailed to open file\n", 2);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	ft_initmap(map, line, state);
	while (line && ft_checkline(line, map))
	{
		map->height += 1;
		free(line);
		line = get_next_line(fd);
	}
	if ((line && !ft_checkline(line, map))
		|| map->borders < 2 || map->player != 1 || map->exit != 1
		|| map->collectible < 1 || map->last_border != map->height)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	ft_findexit(char **plan, t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (plan[y][x] == 'E')
			{
				map->e_pos[0] = x;
				map->e_pos[1] = y;
				return (1);
			}
		}
	}
	return (0);
}
