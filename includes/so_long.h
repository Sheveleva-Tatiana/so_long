/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:32:53 by sshera            #+#    #+#             */
/*   Updated: 2021/12/10 17:38:29 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_opengl_20191021/mlx.h"
# include "../lib/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define SIZEIMAGE 40

typedef struct s_field
{
	char	**map;
	int		height;
	int		empty;
	int		width;
	int		player;
	int		collect;
	int		exit;
	int		steps;
	void	*mlx;
	void	*win;
	int		pl_x;
	int		pl_y;
	void	*ground;
	void	*wall;
	void	*enemy;
	void	*exit_img;
	void	*coll_img;
	void	*collred_img;
	void	*plrup_img;
	void	*plrup2_img;
	void	*plrdown_img;
	void	*plrleft_img;
	void	*plrright_img;
	void	*plrleft2_img;
	void	*plrr2_img;
	int		ter_x;
	int		ter_y;
	int		winner;
	int		enemys;
	int		c_step;
	int		l_step;
	int		u_step;

}	t_field;

char	**read_map(char *file);
void	valid_map(t_field *game);
void	print_error(char *text, int fd);
void	run_game(t_field *game);
void	put_images(t_field *game, int i, int j);
int		open_images(t_field *game);
void	go_right(t_field *game);
void	go_left(t_field *game);
void	go_down(t_field *game);
void	go_up(t_field *game);
void	check_enemy(t_field *game);
int		close_game(void);
int		animation(t_field *game);
int		mv_enemy(t_field *game);
void	win(t_field *game, int flag);
void	game_over(t_field *game);

#endif
