/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_run_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:51:41 by sshera            #+#    #+#             */
/*   Updated: 2021/12/10 17:07:22 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_enemy(t_field *game)
{
	if (game->map[game->pl_y][game->pl_x] == 'T')
		game_over(game);
}

int	key_press(int key, t_field *game)
{
	if (key == 53)
	{
		printf("Bye, bye! See you soon!");
		exit(0);
	}
	if (key == 13)
		go_up(game);
	if (key == 1)
		go_down(game);
	if (key == 0)
		go_left(game);
	if (key == 2)
		go_right(game);
	check_enemy(game);
	put_images(game, 0, 0);
	return (0);
}

void	run_game(t_field *game)
{
	int	win_h;
	int	win_w;

	game->mlx = mlx_init();
	win_h = game->height * SIZEIMAGE;
	win_w = game->width * SIZEIMAGE;
	game->win = mlx_new_window(game->mlx, win_w, win_h, "so_long");
	if (open_images(game) == -1)
		print_error("Ups! I cant't open images!\n", 0);
	put_images(game, 0, 0);
	mlx_key_hook(game->win, key_press, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_hook(game->win, 17, 0L, close_game, 0);
	mlx_loop(game->mlx);
}
