/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:26:13 by rafnasci          #+#    #+#             */
/*   Updated: 2023/11/23 11:25:23 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/include/libft.h"

void	ft_initmap(t_map *map, char *line)
{
	map->width = ft_strlen(line);
	map->height = 0;
	map->collectible = 0;
	map->exit = 0;
	map->player = 0;
}

int	ft_linecomposition(char *line, t_map *map)
{
	size_t	i;
	size_t	check;

	if (line[0] != 1 && line[ft_strlen(line) - 1] != 1)
		perror("Map not closed by walls");
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
			perror("Invalid character in map");
	}
	if (check == ft_strlen(line))
		return (1);
	return (0);
}

int	ft_checkmap(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		border;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror("Failed to open file");
	border = 0;
	line = get_next_line(fd);
	ft_initmap(map, line);
	map->width = ft_strlen(line);
	while (line)
	{
		if (ft_linecomposition(line, map))
			border++;
		free(line);
		line = get_next_line(fd);
		if ((int) ft_strlen(line) != map->width)
			perror("Curved map border");
		map->height += 1;
	}
	if (map->height == map->width || border != 2 || map->player != 1
		|| map->collectible < 1 || map->exit != 1)
		perror("Invalid map");
	return (1);
}
