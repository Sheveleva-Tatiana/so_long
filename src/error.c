/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:11:31 by sshera            #+#    #+#             */
/*   Updated: 2021/12/10 16:56:24 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_over(t_field *game)
{
	win(game, 0);
	printf("Game_over\n");
}

int	close_game(void)
{
	printf("Bye, bye! See you soon!");
	exit (0);
	return (1);
}

void	print_error(char *text, int fd)
{
	if (fd)
	{
		printf("Error\n%sAsk Tanya, what to do!:)\n", text);
		close(fd);
	}
	else
		printf("Error\n%s", text);
	exit(0);
}

void	put_images_win(t_field *game, int i, int j)
{
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
			game->map[j++][i] = '1';
		i++;
	}
}

void	win(t_field *game, int flag)
{
	int	iw;
	int	ih;

	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./img/ground.xpm", &iw, &ih);
	put_images_win(game, 0, 0);
	if (flag == 1)
	{
		game->winner = 1;
		printf("YOU'RE BREATHTAKING!");
	}
	else
		game->winner = -1;
}
