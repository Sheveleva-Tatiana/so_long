/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_valid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:06:26 by sshera            #+#    #+#             */
/*   Updated: 2021/12/17 10:33:35 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_object(t_field *game, int i, int j)
{
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				game->collect++;
			if (game->map[i][j] == 'P')
			{
				game->pl_x = j;
				game->pl_y = i;
				game->player++;
			}
			if (game->map[i][j] == 'E')
				game->exit++;
			if (game->map[i][j] == '0')
				game->empty++;
		}
	}
	if (game->player != 1 || game->exit < 1 || game->collect < 1
		|| game->empty < 1)
		print_error("I don't like your map!\n", 0);
}

void	check_edges(t_field *game, int h, int w)
{
	int	w_c;

	w_c = w;
	while (w >= 0)
	{
		if (game->map[0][w] != '1' || game->map[h][w] != '1')
			print_error("I don't like your map!\n", 0);
		w--;
	}
	while (h >= 0)
	{
		if (game->map[h][0] != '1' || game->map[h][w_c] != '1')
			print_error("I don't like your map!\n", 0);
		h--;
	}
}

void	valid_map(t_field *game)
{
	int	h;
	int	w;

	h = 0;
	w = (int)ft_strlen(game->map[0]);
	game->width = w;
	while (game->map[h])
	{
		if ((int)ft_strlen(game->map[h]) != w)
			print_error("Man, map is bad! I don't play your games!\n", 0);
		h++;
	}
	game->height = h;
	check_object(game, -1, -1);
	check_edges(game, h - 1, w - 1);
}
