/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_put_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:05:49 by sshera            #+#    #+#             */
/*   Updated: 2021/12/10 17:13:09 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_image_to_window(char c, t_field *game, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->ground, x, y);
	else if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coll_img, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->plrdown_img, x, y);
	else if (c == 'U')
		mlx_put_image_to_window(game->mlx, game->win, game->plrup_img, x, y);
	else if (c == 'u')
		mlx_put_image_to_window(game->mlx, game->win, game->plrup2_img, x, y);
	else if (c == 'L')
		mlx_put_image_to_window(game->mlx, game->win, game->plrleft_img, x, y);
	else if (c == 'R')
		mlx_put_image_to_window(game->mlx, game->win, game->plrright_img, x, y);
	else if (c == 'l')
		mlx_put_image_to_window(game->mlx, game->win, game->plrleft2_img, x, y);
	else if (c == 'r')
		mlx_put_image_to_window(game->mlx, game->win, game->plrr2_img, x, y);
	else if (c == 'T')
		mlx_put_image_to_window(game->mlx, game->win, game->enemy, x, y);
}

int	animation(t_field *game)
{
	static int	u;
	int			w;
	int			h;

	if (u % 15 == 0)
		game->coll_img = mlx_xpm_file_to_image(game->mlx,
				"./img/collect2.xpm", &w, &h);
	if (u % 30 == 0)
		game->coll_img = mlx_xpm_file_to_image(game->mlx,
				"./img/collect3.xpm", &w, &h);
	if (u % 45 == 0)
		game->coll_img = mlx_xpm_file_to_image(game->mlx,
				"./img/collect1.xpm", &w, &h);
	if (game->winner == 1 || game->winner == -1)
	{
		if (u % 300 == 0)
			exit (0);
	}
	u++;
	if (game->enemys)
		mv_enemy(game);
	put_images(game, 0, 0);
	return (0);
}

void	check_winner(t_field *game, int s_x, int s_y, char *s)
{
	if (game->winner == 0)
		mlx_string_put(game->mlx, game->win, 5, 5, 0x000000, s);
	else if (game->winner == 1)
		mlx_string_put(game->mlx, game->win, s_x, s_y, \
		0x000000, "YOU WIN");
	else if (game->winner == -1)
		mlx_string_put(game->mlx, game->win, s_x, s_y, \
		0x000000, "GAME OVER");
}

void	put_images(t_field *game, int i, int j)
{
	int		w;
	char	*s;
	int		s_x;
	int		s_y;

	w = SIZEIMAGE;
	s_x = (game->width * w - w) / 2;
	s_y = (game->height * w - w) / 2;
	s = ft_itoa(game->steps);
	mlx_clear_window(game->mlx, game->win);
	while (i < game->width)
	{
		j = -1;
		while (++j < game->height)
		{
			check_winner(game, s_x, s_y, s);
			put_image_to_window(game->map[j][i], game, (i * w), (j * w));
		}
		i++;
	}
	free(s);
}
