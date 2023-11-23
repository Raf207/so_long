/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:26:13 by rafnasci          #+#    #+#             */
/*   Updated: 2023/11/23 15:42:36 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/include/libft.h"

int	ft_checkborders(char *line, t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
		if (line[i] != '1')
			return (1);
	if (map->height == 0)
		return (0);
	map->last_border = map->height;
	return (0);
}

void	ft_initmap(t_map *map, char *line)
{
	map->width = ft_strlen(line);
	map->height = 0;
	map->collectible = 0;
	map->exit = 0;
	map->player = 0;
	map->borders = 0;
}

int	ft_checkline(char *line, t_map *map)
{
	size_t	i;
	size_t	check;

	if ((line[0] != '1' && line[ft_strlen(line) - 1] != '1') 
		|| ((int) ft_strlen(line) != map->width)
		|| ft_checkborders(line, map))
		return (0);
	i = -1;
	check = 0;
	while (++i < ft_strlen(line))
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
	if (check == ft_strlen(line))
		map->borders += 1;
	return (1);
}

int	ft_checkmap(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nFailed to open file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	ft_initmap(map, line);
	while (line && ft_checkline(line, map))
	{
		map->height += 1;
		free(line);
		line = get_next_line(fd);
	}
	if (line && !ft_checkline(line, map) || map->height == map->width 
		|| map->borders != 2 || map->player != 1 || map->exit != 1
		|| map->collectible < 1 || map->last_border != map->height)
	{
		perror("Error\nInvalid map");
		exit(EXIT_FAILURE);
	}
	return (1);
}
