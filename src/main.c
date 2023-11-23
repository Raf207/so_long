/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:38:21 by rafnasci          #+#    #+#             */
/*   Updated: 2023/11/23 18:18:28 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/include/libft.h"

int	ft_checkfile(char *file)
{
	if (((ft_strlen(file) - 1) == 'r') && ((ft_strlen(file) - 2) == 'r')
		&& ((ft_strlen(file) - 3) == 'b') && ((ft_strlen(file) - 4) == '.'))
		return (1);
	else 
		perror("Wrong type of file");
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		if (ft_checkfile(argv[1]) && ft_checkmap(argv[1], &map))
		{
			if (!ft_checkpath(argv[1], &map))
			{
				perror("Error\nNo correct path found");
				exit(EXIT_FAILURE);
			}
		}
		else
			printf("nono");
	}
	return (0);
}
