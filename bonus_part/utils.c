/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:48:15 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/27 18:48:16 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		ft_printf("%s", array[i++]);
}

void	cow_print(t_data *all, int i, int j, int random)
{
	if (random == 9 && i != 0)
	{
		mlx_put_image_to_window(all->mlx, all->win, all->deco[random], \
			j * 71 + 10, i * 71 + 20);
	}
}

void	draw_in_grass(t_data *all, int i, int j)
{
	int	random;

	mlx_put_image_to_window(all->mlx, all->win, all->grass, j * 71, i * 71);
	random = rand() % 16;
	if (random <= 6 && i != 0)
		mlx_put_image_to_window(all->mlx, all->win, all->deco[random], \
			j * 71 + 1 + (rand() % 21), i * 71 + 1 + (rand() % 21));
	if (random == 7 && all->grid[i + 1] && all->grid[i + 1][j] == '1'
		&& i != 0)
	{
		mlx_put_image_to_window(all->mlx, all->win, all->grass, j * 71, \
			(i + 1) * 71);
		mlx_put_image_to_window(all->mlx, all->win, all->deco[random], \
			j * 71 + 1 + (rand() % 21), i * 71 + 1 + (rand() % 21));
		all->grid[i + 1][j] = 'n';
	}
	if (random == 8 && all->grid[i][j + 1] == '1' && i != 0)
	{
		mlx_put_image_to_window(all->mlx, all->win, all->grass, (j + 1) * 71, \
			i * 71);
		mlx_put_image_to_window(all->mlx, all->win, all->deco[random], \
			j * 71 + 1 + (rand() % 21), i * 71 + 1 +(rand() % 21));
		all->grid[i][j + 1] = 'n';
	}
	cow_print(all, i, j, random);
}
