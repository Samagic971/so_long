/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:39:30 by sastier-          #+#    #+#             */
/*   Updated: 2024/05/01 12:39:32 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_data *all)
{
	free_array(all->grid);
	mlx_destroy_window(all->mlx, all->win);
	exit(0);
}

void	print_bunny(t_data *all, void *img)
{
	mlx_put_image_to_window(all->mlx, all->win, all->dirt, all->pos_y * 71, \
			all->pos_x * 71);
	if (all->grid[all->pos_x][all->pos_y] == 'c'
		|| all->grid[all->pos_x][all->pos_y] == 'f')
	{
		if (all->grid[all->pos_x][all->pos_y] == 'c')
			all->coll--;
		all->grid[all->pos_x][all->pos_y] = 'f';
		mlx_put_image_to_window(all->mlx, all->win, all->collect[1], \
			all->pos_y * 71, all->pos_x * 71);
	}
	if (all->grid[all->pos_x][all->pos_y] == 'e')
		mlx_put_image_to_window(all->mlx, all->win, all->exit, all->pos_y * \
		71 + 4, all->pos_x * 71 + 4);
	if (img)
		mlx_put_image_to_window(all->mlx, all->win, img, all->pos_y * 71, \
				all->pos_x * 71);
}

void	left_right(int keydown, t_data *all)
{
	print_bunny(all, NULL);
	if (keydown == 0 || keydown == 123)
	{
		if (all->grid[all->pos_x][all->pos_y - 1] != '1')
		{
			all->pos_y--;
			print_mov(all);
		}
		print_bunny(all, all->bunny[1 + ((all->bunny_state / 4) * 4)]);
		all->bunny_state = 1 + ((all->bunny_state / 4) * 4);
	}
	else if (keydown == 2 || keydown == 124)
	{
		if (all->grid[all->pos_x][all->pos_y + 1] != '1')
		{
			all->pos_y++;
			print_mov(all);
		}
		print_bunny(all, all->bunny[3 + ((all->bunny_state / 4) * 4)]);
		all->bunny_state = 3 + ((all->bunny_state / 4) * 4);
	}
}

void	up_down(int keydown, t_data *all)
{
	print_bunny(all, NULL);
	if (keydown == 13 || keydown == 126)
	{
		if (all->grid[all->pos_x - 1][all->pos_y] != '1')
		{
			all->pos_x--;
			print_mov(all);
		}
		print_bunny(all, all->bunny[2 + ((all->bunny_state / 4) * 4)]);
		all->bunny_state = 2 + ((all->bunny_state / 4) * 4);
	}
	else if (keydown == 1 || keydown == 125)
	{
		if (all->grid[all->pos_x + 1][all->pos_y] != '1')
		{
			all->pos_x++;
			print_mov(all);
		}
		print_bunny(all, all->bunny[0 + ((all->bunny_state / 4) * 4)]);
		all->bunny_state = 0 + ((all->bunny_state / 4) * 4);
	}
}

int	hook_event(int keydown, t_data *all)
{
	if (keydown == 53 || all->game_state == 1)
		close_window(all);
	if (all->game_state == 0)
	{
		if (ft_strchr("\x02{|", keydown) || keydown == 0)
			left_right(keydown, all);
		else if (ft_strchr("\x01\x0D~}", keydown))
			up_down(keydown, all);
		if (all->coll == 0 && all->grid[all->pos_x][all->pos_y] == 'e')
		{
			ft_printf("Congrats ! You ate all the fruits in %d move\n", \
				all->mov);
			end_screen(keydown, all);
		}
	}
	return (1);
}
