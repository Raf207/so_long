/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:54:24 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/25 13:08:50 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/include/libft.h"

void	ft_freeplan(char **plan)
{
	int	i;

	i = -1;
	while (plan[++i])
		free(plan[i]);
	free(plan);
}

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
		perror("Error\nFailed to open file");
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

int	ft_backtrack(int x, int y, t_map *map, char **plan)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (plan[y][x] == 'E')
		return (1);
	if (plan[y][x] == '0' || plan[y][x] == 'C' || plan[y][x] == 'P')
	{
		plan[y][x] = 'V';
		if (ft_backtrack(x + 1, y, map, plan)
			|| ft_backtrack(x - 1, y, map, plan)
			|| ft_backtrack(x, y + 1, map, plan)
			|| ft_backtrack(x, y - 1, map, plan))
			return (1);
	}
	return (0);
}

int	ft_checkpath(char *file, t_map *map)
{
	map->plan = ft_createplan(file, map);
	if (!map->plan)
	{
		perror("Error\nMemory allocation failed");
		exit(EXIT_FAILURE);
	}
	ft_findexit(map->plan, map);
	if (ft_findplayer(map->plan, map) 
		&& ft_backtrack(map->p_pos[0], map->p_pos[1], map, map->plan))
	{
		free(map->plan);
		map->plan = ft_createplan(file, map);
		return (1);
	}
	else
	{
		ft_freeplan(map->plan);
		perror("Error\nNo correct path found.");
		return (0);
	}
}
