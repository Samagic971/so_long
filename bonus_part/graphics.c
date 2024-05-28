/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:17:42 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/30 18:17:43 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_image(t_data *all)
{
	if (!all->bunny[0] || !all->bunny[1] || !all->bunny[2] || !all->bunny[3]
		|| !all->bunny[4] || !all->bunny[5] || !all->bunny[6] || !all->bunny[7]
		|| !all->dirt || !all->grass || !all->exit || !all->collect[0]
		|| !all->collect[1]
		|| !all->num[0] || !all->num[1] || !all->num[2] || !all->num[3]
		|| !all->num[4] || !all->num[5] || !all->num[6] || !all->num[7]
		|| !all->num[8] || !all->num[9]
		|| !all->chick[0] || !all->chick[1] || !all->chick[2] || !all->chick[3]
		|| !all->deco[0] || !all->deco[1] || !all->deco[2] || !all->deco[3]
		|| !all->deco[4] || !all->deco[5] || !all->deco[6] || !all->deco[7]
		|| !all->deco[8] || !all->deco[9] || !all->deco[10])
		return (0);
	return (1);
}

int	init_sprite(t_data *all)
{
	all->grass = mlx_xpm_file_to_image(all->mlx, "./sprite/grass.xpm", \
		&all->temp, &all->temp);
	all->dirt = mlx_xpm_file_to_image(all->mlx, "./sprite/dirt.xpm", \
		&all->temp, &all->temp);
	all->collect[0] = mlx_xpm_file_to_image(all->mlx, "./sprite/collect.xpm", \
		&all->temp, &all->temp);
	all->collect[1] = mlx_xpm_file_to_image(all->mlx, "./sprite/fruit.xpm", \
		&all->temp, &all->temp);
	all->exit = mlx_xpm_file_to_image(all->mlx, "./sprite/exit.xpm", \
		&all->temp, &all->temp);
	all->chick[0] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/chicken/left_1.xpm", &all->temp, &all->temp);
	all->chick[1] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/chicken/right_1.xpm", &all->temp, &all->temp);
	all->chick[2] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/chicken/left_2.xpm", &all->temp, &all->temp);
	all->chick[3] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/chicken/right_2.xpm", &all->temp, &all->temp);
	return (init_sprite_num(all));
}

void	print_sprite(t_data *all, int i, int j)
{
	if (all->grid[i][j] == '1')
		draw_in_grass(all, i, j);
	else if (all->grid[i][j] == '0' || all->grid[i][j] == 'o' || \
		all->grid[i][j] == 'c' || all->grid[i][j] == 'P' || \
		all->grid[i][j] == 'e')
		mlx_put_image_to_window(all->mlx, all->win, all->dirt, j * 71, i * 71);
	if (all->grid[i][j] == 'c')
		mlx_put_image_to_window(all->mlx, all->win, all->collect[0], \
			j * 71 + 10, i * 71 + 10);
	if (all->grid[i][j] == 'e')
		mlx_put_image_to_window(all->mlx, all->win, all->exit, j * 71 + 4, \
			i * 71 + 4);
	if (all->grid[i][j] == 'P')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->bunny[0], \
			j * 71, i * 71);
		all->pos_x = i;
		all->pos_y = j;
		all->bunny_state = 0;
	}
	if (all->grid[i][j] == 'x' || all->grid[i][j] == 'X')
		init_chick(all, i, j);
	if (all->grid[i][j] == 'n')
		all->grid[i][j] = '1';
}

void	draw_map(t_data *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->grid[i])
	{
		j = 0;
		while (all->grid[i][j] != '\n')
			print_sprite(all, i, j++);
		i++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->num[0], \
		all->screen_x - 44, 3);
}

void	launch(t_data *all)
{
	all->mlx = mlx_init();
	all->screen_y = all->width_grid * 71;
	all->screen_x = all->length_grid * 71;
	all->win = mlx_new_window(all->mlx, all->screen_x, all->screen_y, \
		"Hello Bunny");
	all->game_state = 0;
	if (init_sprite(all) == 0)
	{
		ft_putendl_fd("Problem creating the sprites", 2);
		close_window(all);
	}
	srand((unsigned int)time(NULL));
	draw_map(all);
	mlx_do_sync(all->mlx);
	all->frame = 0;
	all->mov = 0;
	mlx_hook(all->win, 2, 1L << 0, hook_event, all);
	mlx_hook(all->win, 17, 0, (void *)close_window, all);
	mlx_loop_hook(all->mlx, update_win, all);
	mlx_loop(all->mlx);
}
