/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:36:56 by rafnasci          #+#    #+#             */
/*   Updated: 2024/02/25 13:07:40 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/include/libft.h"

typedef struct s_map
{
	char	**plan;
	int		height;
	int		width;
	int		collectible;
	int		exit;
	int		player;
	int		last_border;
	int		borders;
	int		p_pos[2];
	int		e_pos[2];
}	t_map;

typedef struct s_player
{
	void	*p_front;
	void	*p_back;
	void	*p_left;
	void	*p_right;
}	t_player;

typedef struct s_sprites
{
	void	*collectibe;
	void	*grass;
	void	*tree;
	void	*exit;
	void	*player;
}	t_sprites;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
}	t_ptr;

typedef struct s_gamestate
{
	int	collected;
	int	completed;
	int	moves;
}	t_state;

typedef struct s_game
{
	t_ptr		ptr;
	t_sprites	sprites;
	t_map		map;
	t_state		state;
}	t_game;

int		ft_checkfile(char *file);
int		ft_checkmap(char *file, t_map *map, t_state *state);
int		ft_checkline(char *line, t_map *map);
int		ft_checkborders(char *line, t_map *map);
void	ft_initmap(t_map *map, char *line, t_state *state);
int		ft_checkpath(char *file, t_map *map);
int		ft_backtrack(int x, int y, t_map *map, char **plan);
int		ft_checkborders(char *line, t_map *map);
int		ft_findplayer(char **plan, t_map *map);
int		main(int argc, char **argv);
void	ft_createwin(t_game *game);
void	ft_init_ptr(t_ptr *ptr, t_map *map);
void	ft_init_img(t_sprites *assets, t_ptr *ptr);
void	ft_display_background(t_map *map, t_sprites *sprites, t_ptr *ptr);
void	ft_display_map(t_game *game);
void	ft_display_player(t_game *game);
int		ft_displayall(t_game *game);
int		ft_move_ok(t_map *map, int x, int y, t_game *game);
int		ft_key_handler(int keycode, t_game *game);
void	ft_swap(t_map *map, int keycode);
void	ft_move(int keycode, t_game *game);
void	ft_freeplan(char **plan);
void	ft_destroy_img(t_game *game);
void	ft_exit(t_game *game);
int		ft_findexit(char **plan, t_map *map);

#endif