/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:54:24 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/20 00:01:08 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_findplayer(char **plan, t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (plan[y][x] == 'P')
			{
				map->p_pos[0] = x;
				map->p_pos[1] = y;
				return (1);
			}
		}
	}
	return (0);
}

char	**ft_createplan(char *file, t_map *map)
{
	char	**plan;
	int		fd;
	char	*line;
	int		i;

	plan = ft_calloc(sizeof(char *), map->height + 1);
	if (!plan)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nFailed to open file\n", 2);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < map->height)
	{
		line = get_next_line(fd);
		plan[i] = (char *) malloc (sizeof(char) * (map->width + 1));
		if (!plan[i] || !line)
			return (ft_freeplan(plan), free(line), NULL);
		ft_strlcpy(plan[i], line, map->width + 1);
		free(line);
	}
	return (plan);
}

int	ft_backtrack_exit(int x, int y, t_map *map, char **plan)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (plan[y][x] == 'E')
		return (1);
	if (plan[y][x] == '0' || plan[y][x] == 'C' || plan[y][x] == 'P')
	{
		plan[y][x] = 'V';
		if (ft_backtrack_exit(x - 1, y, map, plan)
			|| ft_backtrack_exit(x + 1, y, map, plan)
			|| ft_backtrack_exit(x, y + 1, map, plan)
			|| ft_backtrack_exit(x, y - 1, map, plan))
			return (1);
	}
	return (0);
}

int	ft_backtrack_collect(int x, int y, t_map *map, char **plan)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (map->coll_isok == map->collectible)
		return (1);
	if (plan[y][x] == '0' || plan[y][x] == 'C' || plan[y][x] == 'P'
			|| plan[y][x] == 'E')
	{
		if (plan[y][x] == 'C')
			map->coll_isok++;
		plan[y][x] = 'V';
		if (ft_backtrack_collect(x - 1, y, map, plan)
			|| ft_backtrack_collect(x + 1, y, map, plan)
			|| ft_backtrack_collect(x, y + 1, map, plan)
			|| ft_backtrack_collect(x, y - 1, map, plan))
			return (1);
	}
	return (0);
}

int	ft_checkpath(char *file, t_map *map)
{
	char	**plan2;

	plan2 = ft_createplan(file, map);
	map->plan = ft_createplan(file, map);
	if (!map->plan || !plan2)
	{
		ft_putstr_fd("Error\nMemory allocation failed", 2);
		exit(EXIT_FAILURE);
	}
	ft_findexit(map->plan, map);
	if (ft_findplayer(map->plan, map)
		&& ft_backtrack_exit(map->p_pos[0], map->p_pos[1], map, plan2)
		&& ft_backtrack_collect(map->p_pos[0], map->p_pos[1], map, map->plan)
		&& map->coll_isok == map->collectible)
	{
		ft_freeplan(plan2);
		ft_freeplan(map->plan);
		map->plan = ft_createplan(file, map);
		return (1);
	}
	else
	{
		ft_putstr_fd("Error\nNo correct path found.", 2);
		return (ft_freeplan(map->plan), ft_freeplan(plan2), 0);
	}
}
