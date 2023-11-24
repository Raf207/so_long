/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:38:21 by rafnasci          #+#    #+#             */
/*   Updated: 2023/11/24 16:30:30 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"

int	ft_checkfile(char *file)
{
	if ((file[ft_strlen(file) - 1] == 'r') && (file[ft_strlen(file) - 2] == 'e')
		&& (file[ft_strlen(file) - 3] == 'b')
		&& (file[ft_strlen(file) - 4] == '.'))
		return (1);
	else 
	{
		perror("Wrong type of file");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		if (ft_checkfile(argv[1]) && ft_checkmap(argv[1], &map)
			&& ft_checkpath(argv[1], &map))
		{
			printf("yee");
		}
	}
	return (0);
}
