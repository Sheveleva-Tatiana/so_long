/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:32:21 by sshera            #+#    #+#             */
/*   Updated: 2021/12/10 16:49:08 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_enemy(t_field *game)
{
	if (game->width > 6 && game->height > 3)
	{
		if (!(ft_strchr("1ECP", game->map[game->height - 2]
					[game->width - 3])))
		{
			game->map[game->height - 2][game->width - 3] = 'T';
			game->ter_x = game->width - 3;
			game->ter_y = game->height - 2;
			game->enemys = 1;
		}
	}
}

void	creat_struct(t_field *game)
{
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->empty = 0;
	game->player = 0;
	game->collect = 0;
	game->exit = 0;
	game->steps = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->ter_x = 0;
	game->ter_y = 0;
	game->winner = 0;
	game->enemys = 0;
	game->c_step = 0;
	game->l_step = 0;
	game->u_step = 0;
}

void	check_extension(char *ber)
{
	size_t	len;

	len = ft_strlen(ber);
	if ((ft_strncmp(&ber[len - 4], ".ber", 4)) == 0)
		return ;
	else
		print_error("Whats up, man?! Where is my correct map?!\n", 0);
}

int	main(int argc, char **argv)
{
	t_field	game;

	if (argc == 2)
	{
		check_extension(argv[1]);
		creat_struct(&game);
		game.map = read_map(argv[1]);
		valid_map(&game);
		put_enemy(&game);
		run_game(&game);
	}
	else
		print_error("Hey, man! You do something wrong!\n", 0);
	return (0);
}
