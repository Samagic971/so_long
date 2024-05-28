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
	if (all->grid[all->pos_x][all->pos_y] == 'c')
	{
		all->grid[all->pos_x][all->pos_y] = 'o';
		all->coll--;
		mlx_put_image_to_window(all->mlx, all->win, all->dirt, all->pos_y * 71, \
			all->pos_x * 71);
	}
	if (all->grid[all->pos_x][all->pos_y] == 'e')
		mlx_put_image_to_window(all->mlx, all->win, all->exit, all->pos_y * \
		71 + 4, all->pos_x * 71 + 4);
	mlx_put_image_to_window(all->mlx, all->win, img, all->pos_y * 71, \
			all->pos_x * 71);
}

void	left_right(int keydown, t_data *all)
{
	mlx_put_image_to_window(all->mlx, all->win, all->dirt, all->pos_y * 71, \
			all->pos_x * 71);
	if (all->grid[all->pos_x][all->pos_y] == 'e')
		mlx_put_image_to_window(all->mlx, all->win, all->exit, all->pos_y * \
		71 + 4, all->pos_x * 71 + 4);
	if (keydown == 0 || keydown == 123)
	{
		if (all->grid[all->pos_x][all->pos_y - 1] != '1')
		{
			all->pos_y--;
			all->mov++;
		}
		print_bunny(all, all->left);
	}
	else if (keydown == 2 || keydown == 124)
	{
		if (all->grid[all->pos_x][all->pos_y + 1] != '1')
		{
			all->pos_y++;
			all->mov++;
		}
		print_bunny(all, all->right);
	}
}

void	up_down(int keydown, t_data *all)
{
	mlx_put_image_to_window(all->mlx, all->win, all->dirt, all->pos_y * 71, \
			all->pos_x * 71);
	if (all->grid[all->pos_x][all->pos_y] == 'e')
		mlx_put_image_to_window(all->mlx, all->win, all->exit, all->pos_y * \
		71 + 4, all->pos_x * 71 + 4);
	if (keydown == 13 || keydown == 126)
	{
		if (all->grid[all->pos_x - 1][all->pos_y] != '1')
		{
			all->pos_x--;
			all->mov++;
		}
		print_bunny(all, all->back);
	}
	else if (keydown == 1 || keydown == 125)
	{
		if (all->grid[all->pos_x + 1][all->pos_y] != '1')
		{
			all->pos_x++;
			all->mov++;
		}
		print_bunny(all, all->front);
	}
}

int	hook_event(int keydown, t_data *all)
{
	int	mov;

	mov = all->mov;
	if (keydown == 53)
		close_window(all);
	else if (ft_strchr("\x02{|", keydown) || keydown == 0)
		left_right(keydown, all);
	else if (ft_strchr("\x01\x0D~}", keydown))
		up_down(keydown, all);
	if (mov != all->mov)
		ft_printf("%d movements, %d collectibles remain\n", mov + 1, all->coll);
	if (all->coll == 0 && all->grid[all->pos_x][all->pos_y] == 'e')
	{
		ft_printf("Congrats ! You ate all the fruits in %d move\n", all->mov);
		close_window(all);
	}
	return (1);
}
