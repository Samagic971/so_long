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
	if (!all->front || !all->back || !all->left || !all->right || !all->dirt \
		|| !all->grass || !all->exit || !all->collect)
		return (0);
	return (1);
}

int	init_sprite(t_data *all)
{
	all->front = mlx_xpm_file_to_image(all->mlx, "./sprite/bunny/front_1.xpm", \
		&all->temp, &all->temp);
	all->back = mlx_xpm_file_to_image(all->mlx, "./sprite/bunny/back_1.xpm", \
		&all->temp, &all->temp);
	all->left = mlx_xpm_file_to_image(all->mlx, "./sprite/bunny/left_1.xpm", \
		&all->temp, &all->temp);
	all->right = mlx_xpm_file_to_image(all->mlx, "./sprite/bunny/right_1.xpm", \
		&all->temp, &all->temp);
	all->grass = mlx_xpm_file_to_image(all->mlx, "./sprite/grass.xpm", \
		&all->temp, &all->temp);
	all->dirt = mlx_xpm_file_to_image(all->mlx, "./sprite/dirt.xpm", \
		&all->temp, &all->temp);
	all->collect = mlx_xpm_file_to_image(all->mlx, "./sprite/collect.xpm", \
		&all->temp, &all->temp);
	all->exit = mlx_xpm_file_to_image(all->mlx, "./sprite/exit.xpm", \
		&all->temp, &all->temp);
	return (check_image(all));
}

void	print_sprite(t_data *all, int i, int j)
{
	if (all->grid[i][j] == '1')
		mlx_put_image_to_window(all->mlx, all->win, all->grass, j * 71, i * 71);
	if (all->grid[i][j] == '0' || all->grid[i][j] == 'o' || \
		all->grid[i][j] == 'c' || all->grid[i][j] == 'P' || \
		all->grid[i][j] == 'e')
		mlx_put_image_to_window(all->mlx, all->win, all->dirt, j * 71, i * 71);
	if (all->grid[i][j] == 'c')
		mlx_put_image_to_window(all->mlx, all->win, all->collect, j * 71 + 10, \
			i * 71 + 10);
	if (all->grid[i][j] == 'e')
		mlx_put_image_to_window(all->mlx, all->win, all->exit, j * 71 + 4, \
			i * 71 + 4);
	if (all->grid[i][j] == 'P')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->front, j * 71, i * 71);
		all->pos_x = i;
		all->pos_y = j;
	}
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
}

void	launch(t_data *all)
{
	all->mlx = mlx_init();
	all->screen_y = all->width_grid * 71;
	all->screen_x = all->length_grid * 71;
	all->win = mlx_new_window(all->mlx, all->screen_x, all->screen_y, \
		"Hello Bunny");
	if (init_sprite(all) == 0)
	{
		ft_putendl_fd("Problem creating the sprites", 2);
		close_window(all);
	}
	draw_map(all);
	mlx_do_sync(all->mlx);
	mlx_hook(all->win, 2, 1L << 0, hook_event, all);
	mlx_hook(all->win, 17, 0, (void *)close_window, all);
	mlx_loop(all->mlx);
}
