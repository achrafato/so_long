/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:33:30 by aibn-che          #+#    #+#             */
/*   Updated: 2024/02/19 16:22:11 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../utils/get_next_line.h"
# include <mlx.h>
# define ENEMY_1 "./textures/animation_enemy_1.xpm"
# define ENEMY_2 "./textures/animation_enemy_2.xpm"
# define BACK "./textures/back.xpm"
# define FRONT "./textures/front.xpm"
# define LEFT "./textures/left.xpm"
# define RIGHT "./textures/right.xpm"
# define OPENED_DOOR "./textures/nimbus_last.xpm"
# define CLOSED_DOOR "./textures/nimbus.xpm"
# define ANGLES_WALL "./textures/wall_angles_left_right.xpm"
# define WALL_BOTTOM "./textures/wall_bottom.xpm"
# define WALL_TOP "./textures/wall_top.xpm"
# define WALL_CENTER "./textures/rock.xpm"
# define COIN "./textures/coin.xpm"
# define TILE "./textures/ground_1.xpm"

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image;
	char		**arr;
	int			width;
	int			height;
	struct pic	*pic;
}			t_data;

typedef struct long_map
{
	char			*line;
	int				len;
	struct long_map	*next;
}	t_lm;

typedef struct pic
{
	void	*enemy_1;
	void	*enemy_2;
	void	*back;
	void	*front;
	void	*left;
	void	*right;
	void	*coin;
	void	*tile;
	void	*door;
	void	*door_last;
	void	*wall_angles;
	void	*wall_bottom;
	void	*wall_top;
	void	*rock;
}	t_pic;

// arr_utils.c
char	*str_dup(char *str);
char	**to2arr(t_lm *head);
int		item_count(char **arr);
void	free_to_d_arr(char **arr);
int		map_height(char **arr);

// cordinations.c
void	exit_cordination(char **arr, int *x, int *y);
void	door_cordination(char **arr, int *x, int *y);
void	position_cordination( char **arr, int *x, int *y);

//parsing_2.c
void	check_path(char **arr, int x, int y);
int		check_characters_existence(char **arr);
void	check_map_validity(t_lm *map);

//render_pixels_1.c
void	render_exit(t_data data, int i, int j);
void	render_collectibles(t_data data, int i, int j);
void	render_person(t_data data, int i, int j);
void	render_path(t_data data, int i, int j);
void	end_game(t_data *data);

//render_pixels_2.c
void	render_rock(t_data data, int i, int j);
void	render_top_wall(t_data data, int i, int j);
void	render_bottom_wall(t_data data, int i, int j);
void	render_wall_angles_left_right(t_data data, int i, int j);
void	render_open_door(t_data *data);

//struct_utils.c
int		stack_len(t_lm *head);
t_lm	*last_node(t_lm *top);
t_lm	*new_node(char *str);
void	push(char *str, t_lm **map);
void	free_linked_list(t_lm **head);

//movements.c
void	display_movements(t_data *data, int mov);
void	move_right(t_data *data, int x, int y, int *mov);
void	move_left(t_data *data, int x, int y, int *mov);
void	move_up(t_data *data, int x, int y, int *mov);
void	move_down(t_data *data, int x, int y, int *mov);

// enemy_animation_and_movements.c
int		enemy_loop(t_data *data);

// parsing.c
int		check_rectangular_shape(t_lm *head);
void	fill_data(t_data *data, char **arr);
int		check_border(t_lm *head);

// render_pixels.c
void	render_pixels(char **arr);
int		close_window(t_data *data);

// check_xpm_bonus.c
int		check_xpms(t_data *data);
void	*load_image(char *path, t_data *data);
void	destroy_image(t_data *data, t_pic *images);

char	*ft_itoa(int a);

//so_long_bouns_.c
void	update_player_position(char **arr, int x, int y, int key);

#endif