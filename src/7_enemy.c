/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_enemy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:26:46 by sshera            #+#    #+#             */
/*   Updated: 2021/12/17 10:13:12 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_enemy_down(t_field *game, int *flag)
{
	if (!(ft_strchr("1EC", game->map[game->ter_y + 1][game->ter_x])))
	{
		game->map[game->ter_y + 1][game->ter_x] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_y++;
		*flag = 2;
	}
	else
		*flag = 1;
}

void	move_enemy_up(t_field *game, int *flag)
{
	if (!(ft_strchr("1EC", game->map[game->ter_y - 1][game->ter_x])))
	{
		game->map[game->ter_y - 1][game->ter_x] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_y--;
	}
	else
		move_enemy_down(game, flag);
}

void	move_enemy_left(t_field *game, int *flag)
{
	if (!(ft_strchr("1EC", game->map[game->ter_y][game->ter_x - 1])))
	{
		game->map[game->ter_y][game->ter_x - 1] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_x--;
	}
	else
	{
		*flag = 1;
		move_enemy_up(game, flag);
	}
}

void	move_enemy_right(t_field *game, int *flag)
{
	if (!(ft_strchr("1EC", game->map[game->ter_y][game->ter_x + 1])))
	{
		game->map[game->ter_y][game->ter_x + 1] = 'T';
		game->map[game->ter_y][game->ter_x] = '0';
		game->ter_x++;
	}
	else
		*flag = 0;
}

int	mv_enemy(t_field *game)
{
	static int	u;
	static int	flag;

	if (u % 15 == 0 && flag == 0)
		move_enemy_left(game, &flag);
	if (u % 15 == 0 && flag == 1)
		move_enemy_right(game, &flag);
	if (u % 15 == 0 && flag == 2)
		move_enemy_down(game, &flag);
	u++;
	check_enemy(game);
	return (0);
}
