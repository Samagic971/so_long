/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cow_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:59:18 by sastier-          #+#    #+#             */
/*   Updated: 2024/05/06 19:59:20 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_chick(t_data *all)
{
	t_chick	*temp;

	temp = all->chicks;
	while (temp != NULL)
	{
		temp->chick_state += 2;
		while (temp->chick_state >= 4)
			temp->chick_state -= 4;
		print_chick(all, all->chick[temp->chick_state], temp);
		temp = temp->next;
	}
}

int	is_there_chick(t_chick *chick, t_data *all, int x, int y)
{
	t_chick	*temp;

	temp = all->chicks;
	while (temp)
	{
		if (temp != chick)
		{
			if (temp->c_pos_x == chick->c_pos_x + x && temp->c_pos_y == \
				chick->c_pos_y + y)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

void	end_screen(int keydown, t_data *all)
{
	keydown++;
	mlx_destroy_window(all->mlx, all->win);
	all->wallpaper = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/wallpaper.xpm", &all->screen_x, &all->screen_y);
	if (!all->wallpaper)
	{
		ft_putendl_fd("Problem creating the sprites", 2);
		free_array(all->grid);
		exit(0);
	}
	all->win = mlx_new_window(all->mlx, all->screen_x, all->screen_y, "Bravo");
	mlx_put_image_to_window(all->mlx, all->win, all->wallpaper, 0, 0);
	all->game_state = 1;
	mlx_hook(all->win, 17, 0, (void *)close_window, all);
	mlx_hook(all->win, 2, 1L << 0, hook_event, all);
	mlx_loop(all->mlx);
}
