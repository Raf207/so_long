/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafnasci <rafnasci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:59:40 by rafnasci          #+#    #+#             */
/*   Updated: 2024/05/20 00:00:04 by rafnasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	int		coll_isok;
	int		exit;
	int		player;
	int		last_border;
	int		borders;
	int		p_pos[2];
	int		e_pos[2];
}	t_map;

typedef struct s_p_angle
{
	void	*p_front;
	void	*p_f_m1;
	void	*p_f_m2;
	void	*p_back;
	void	*p_b_m1;
	void	*p_b_m2;
	void	*p_left;
	void	*p_l_m1;
	void	*p_l_m2;
	void	*p_right;
	void	*p_r_m1;
	void	*p_r_m2;
}	t_p_angle;

typedef struct s_sprites
{
	void	*collectibe;
	void	*pokeouvert;
	void	*grass;
	void	*tree;
	void	*exit;
	void	*player;
	void	*pokeferme;
	char	angle;
	void	*num0;
	void	*num1;
	void	*num2;
	void	*num3;
	void	*num4;
	void	*num5;
	void	*num6;
	void	*num7;
	void	*num8;
	void	*num9;
	void	*miaous;
	void	*miaous_f;
	void	*miaous_l;
	void	*miaous_r;
	t_p_angle	p_angle;
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
	int	loop;
	int	loop2;
	int	loop3;
	int	img_col;
	int img_col2;
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
int		ft_checkborders(char *line, t_map *map);
int		ft_findplayer(char **plan, t_map *map);
int		main(int argc, char **argv);
void	ft_gameloop(t_game *game);
void	ft_init_ptr(t_ptr *ptr, t_map *map);
void	ft_init_img(t_sprites *assets, t_ptr *ptr);
void	ft_init_move(t_sprites *assets, t_ptr *ptr);
void	ft_display_background(t_map *map, t_sprites *sprites, t_ptr *ptr);
void	ft_display_map(t_game *game);
void	ft_display_player(t_game *game);
int		ft_displayall(t_game *game);
int		ft_move_ok(t_map *map, int x, int y, t_game *game);
int		ft_key_handler(int keycode, t_game *game);
void	ft_swap(t_map *map, int *pos, int i, t_sprites *sprites);
void	ft_move(int keycode, t_game *game);
void	ft_freeplan(char **plan);
void	ft_destroy_img(t_game *game);
int		ft_exit(t_game *game);
int		ft_findexit(char **plan, t_map *map);
void	ft_init_num(t_sprites *assets, t_ptr *ptr);
void	ft_display_num(t_game *game);
void	ft_init_miaouss(t_sprites *assets, t_ptr *ptr);
void	ft_player_anim(t_game *game, int i);
int		ft_loop_collec(t_game *game);
int		ft_loop_player(t_game *game);
int		ft_loop_miaous(t_game *game);

#endif