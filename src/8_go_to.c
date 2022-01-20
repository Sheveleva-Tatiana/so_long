/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_go_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:19:10 by sshera            #+#    #+#             */
/*   Updated: 2021/12/10 16:56:11 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_collect(t_field *game, int y, int x)
{
	if (game->collect == 0)
	{
		if (game->map[game->pl_y - y][game->pl_x - x] == 'E')
		{
			game->steps++;
			printf("Steps: %d\n", game->steps);
			win(game, 1);
		}
	}
}

void	go_up(t_field *game)
{
	check_collect(game, 1, 0);
	if (!(ft_strchr("1E", game->map[game->pl_y - 1][game->pl_x])))
	{
		if (game->map[game->pl_y - 1][game->pl_x] == 'C')
			game->collect--;
		if (game->map[game->pl_y - 1][game->pl_x] == 'T')
			game_over(game);
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_y--;
		if (game->u_step == 0)
		{
			game->map[game->pl_y][game->pl_x] = 'U';
			game->u_step = 1;
		}
		else
		{
			game->map[game->pl_y][game->pl_x] = 'u';
			game->u_step = 0;
		}
		game->steps++;
		printf("Steps: %d\n", game->steps);
	}
}

void	go_down(t_field *game)
{
	check_collect(game, -1, 0);
	if (!(ft_strchr("1E", game->map[game->pl_y + 1][game->pl_x])))
	{
		if (game->map[game->pl_y + 1][game->pl_x] == 'C')
			game->collect--;
		if (game->map[game->pl_y + 1][game->pl_x] == 'T')
			game_over(game);
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_y++;
		game->map[game->pl_y][game->pl_x] = 'P';
		game->steps++;
		printf("Steps: %d\n", game->steps);
	}
}

void	go_left(t_field *game)
{
	check_collect(game, 0, 1);
	if (!(ft_strchr("1E", game->map[game->pl_y][game->pl_x - 1])))
	{
		if (game->map[game->pl_y][game->pl_x - 1] == 'C')
			game->collect--;
		if (game->map[game->pl_y][game->pl_x - 1] == 'T')
			game_over(game);
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_x--;
		if (game->l_step == 0)
		{
			game->map[game->pl_y][game->pl_x] = 'L';
			game->l_step = 1;
		}
		else
		{
			game->map[game->pl_y][game->pl_x] = 'l';
			game->l_step = 0;
		}
		game->steps++;
		printf("Steps: %d\n", game->steps);
	}
}

void	go_right(t_field *game)
{
	check_collect(game, 0, -1);
	if (!(ft_strchr("1E", game->map[game->pl_y][game->pl_x + 1])))
	{
		if (game->map[game->pl_y][game->pl_x + 1] == 'C')
			game->collect--;
		if (game->map[game->pl_y][game->pl_x + 1] == 'T')
			game_over(game);
		game->map[game->pl_y][game->pl_x] = '0';
		game->pl_x++;
		if (game->c_step == 0)
		{
			game->map[game->pl_y][game->pl_x] = 'R';
			game->c_step = 1;
		}
		else
		{
			game->map[game->pl_y][game->pl_x] = 'r';
			game->c_step = 0;
		}
		game->steps++;
		printf("Steps: %d\n", game->steps);
	}
}
