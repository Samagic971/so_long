/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:41:10 by sastier-          #+#    #+#             */
/*   Updated: 2024/05/04 13:41:12 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_chick(t_data *all, void *img, t_chick *chick);

void	move_chick_2(t_data *all, int i, t_chick *chick)
{
	if (i == 2 && !ft_strchr("1c", all->grid[chick->c_pos_x + 1] \
	[chick->c_pos_y]) && is_there_chick(chick, all, 1, 0))
		chick->c_pos_x++;
	if (i == 3 && !ft_strchr("1c", all->grid[chick->c_pos_x] \
	[chick->c_pos_y + 1]) && is_there_chick(chick, all, 0, 1))
		chick->c_pos_y++;
	if (i == 3)
		chick->chick_state = 1 + ((chick->chick_state / 2) * 2);
	if (i == 1)
		chick->chick_state = 0 + ((chick->chick_state / 2) * 2);
	print_chick(all, all->chick[chick->chick_state], chick);
}

void	move_chick(t_data *all, t_chick *c)
{
	int	i;

	i = rand() % 4;
	mlx_put_image_to_window(all->mlx, all->win, all->dirt, c->c_pos_y * 71, \
		c->c_pos_x * 71);
	if (all->grid[c->c_pos_x][c->c_pos_y] == 'e')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->exit, \
			c->c_pos_y * 71 + 4, c->c_pos_x * 71 + 4);
	}
	if (all->grid[c->c_pos_x][c->c_pos_y] == 'f')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->collect[1], \
			c->c_pos_y * 71, c->c_pos_x * 71);
	}
	if (i == 0 && !ft_strchr("1c", all->grid[c->c_pos_x - 1] \
		[c->c_pos_y]) && is_there_chick(c, all, -1, 0))
		c->c_pos_x--;
	if (i == 1 && !ft_strchr("1c", all->grid[c->c_pos_x][c->c_pos_y - 1])
		&& is_there_chick(c, all, 0, -1))
		c->c_pos_y--;
	move_chick_2(all, i, c);
}

void	print_chick(t_data *all, void *img, t_chick *chick)
{
	mlx_put_image_to_window(all->mlx, all->win, all->dirt, chick->c_pos_y * 71, \
			chick->c_pos_x * 71);
	if (all->grid[chick->c_pos_x][chick->c_pos_y] == 'f')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->collect[1], \
			chick->c_pos_y * 71, chick->c_pos_x * 71);
	}
	if (all->grid[chick->c_pos_x][chick->c_pos_y] == 'e')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->exit, \
			chick->c_pos_y * 71 + 4, chick->c_pos_x * 71 + 4);
	}
	if (img)
		mlx_put_image_to_window(all->mlx, all->win, img, chick->c_pos_y * 71, \
				chick->c_pos_x * 71);
}

void	update_win_bis(t_data *all)
{
	t_chick	*chick;

	chick = all->chicks;
	while (chick)
	{
		if (all->pos_x == chick->c_pos_x && all->pos_y == chick->c_pos_y)
		{
			ft_printf("You loose X)\n");
			close_window(all);
		}
		chick = chick->next;
	}
	chick = all->chicks;
	if (all->frame % 8000 == 0)
	{
		while (chick)
		{
			move_chick(all, chick);
			chick = chick->next;
		}
		if (all->frame >= 48000000)
			all->frame = 0;
	}
}

int	update_win(t_data *all)
{
	if (all->game_state == 0)
	{
		all->frame++;
		if (all->frame % 6000 == 0)
		{
			all->bunny_state += 4;
			while (all->bunny_state >= 8)
				all->bunny_state -= 8;
			print_bunny(all, all->bunny[all->bunny_state]);
			update_chick(all);
		}
		update_win_bis(all);
	}
	return (0);
}
