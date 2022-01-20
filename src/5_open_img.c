/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_open_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:07:04 by sshera            #+#    #+#             */
/*   Updated: 2021/12/10 17:08:12 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_enemy(t_field *game)
{
	int	iw;
	int	ih;

	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"./img/dog.xpm", &iw, &ih);
	if (!(game->ground))
		return (-1);
	return (0);
}

int	open_collect(t_field *game)
{
	int	iw;
	int	ih;

	game->coll_img = mlx_xpm_file_to_image(game->mlx,
			"./img/collect1.xpm", &iw, &ih);
	game->collred_img = mlx_xpm_file_to_image(game->mlx,
			"./img/collect2.xpm", &iw, &ih);
	if (!(game->coll_img) || !(game->collred_img))
		return (-1);
	return (0);
}

int	open_ground_wall_exit(t_field *game)
{
	int	iw;
	int	ih;

	game->ground = mlx_xpm_file_to_image(game->mlx,
			"./img/ground.xpm", &iw, &ih);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &iw, &ih);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"./img/exit.xpm", &iw, &ih);
	if (!(game->ground) || !(game->wall) || !(game->exit_img))
		return (-1);
	return (0);
}

int	open_player(t_field *game)
{
	int	iw;
	int	ih;

	game->plrup_img = mlx_xpm_file_to_image(game->mlx,
			"./img/up.xpm", &iw, &ih);
	game->plrup2_img = mlx_xpm_file_to_image(game->mlx,
			"./img/up2.xpm", &iw, &ih);
	game->plrdown_img = mlx_xpm_file_to_image(game->mlx,
			"./img/down.xpm", &iw, &ih);
	game->plrleft_img = mlx_xpm_file_to_image(game->mlx,
			"./img/left.xpm", &iw, &ih);
	game->plrright_img = mlx_xpm_file_to_image(game->mlx,
			"./img/right.xpm", &iw, &ih);
	game->plrleft2_img = mlx_xpm_file_to_image(game->mlx,
			"./img/left2.xpm", &iw, &ih);
	game->plrr2_img = mlx_xpm_file_to_image(game->mlx,
			"./img/right2.xpm", &iw, &ih);
	if (!(game->plrup_img) || !(game->plrdown_img)
		|| !(game->plrleft_img) || !(game->plrright_img)
		|| !(game->plrleft2_img) || !(game->plrr2_img))
		return (-1);
	return (0);
}

int	open_images(t_field *game)
{
	if (open_ground_wall_exit(game) == -1)
		return (-1);
	if (open_collect(game) == -1)
		return (-1);
	if (open_player(game) == -1)
		return (-1);
	if (open_enemy(game) == -1)
		return (-1);
	return (0);
}
