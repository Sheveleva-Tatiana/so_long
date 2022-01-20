/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_read_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:16:41 by sshera            #+#    #+#             */
/*   Updated: 2021/12/17 10:03:15 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_next_line(int fd, int *flag)
{
	char	*str;
	char	buf[2];
	int		byte;

	str = ft_calloc(1, 1);
	if (!str)
		exit(0);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buf, 1);
		if (byte == -1)
			print_error("Ups! I can't read this file :(\n", fd);
		if (buf[0] == '\n' || byte == 0)
			break ;
		if (!(ft_strchr("10CPE", buf[0])))
			print_error("I don't like map! I don't play with you!\n", fd);
		str = ft_strjoin(str, buf);
	}
	if (byte == 0)
		*flag = 0;
	return (str);
}

int	count_linemap(char *file)
{
	int		count_line;
	int		fd;
	int		byte;
	char	buf[2];

	fd = open(file, O_RDONLY);
	count_line = 0;
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buf, 1);
		if (buf[0] == '\n')
			count_line++;
	}
	if (byte == -1)
		print_error("Ups! I can't read this file :(\n", fd);
	close(fd);
	return (count_line);
}

char	**read_map(char *file)
{
	int		count_line;
	int		fd;
	char	**map;
	int		flag;
	int		index;

	count_line = count_linemap(file);
	flag = 1;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char **) * (count_line + 1));
	if (!map)
		print_error("Ups! You want too much from me! :(\n", fd);
	index = -1;
	while (flag)
		map[++index] = get_next_line(fd, &flag);
	map[++index] = NULL;
	close(fd);
	return (map);
}
