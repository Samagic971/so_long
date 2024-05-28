/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:29:24 by sastier-          #+#    #+#             */
/*   Updated: 2024/05/03 15:29:26 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_sprite_bunny(t_data *all);

int	init_sprite_num(t_data *all)
{
	all->num[0] = mlx_xpm_file_to_image(all->mlx, "./sprite/number/zero.xpm", \
		&all->temp, &all->temp);
	all->num[1] = mlx_xpm_file_to_image(all->mlx, "./sprite/number/one.xpm", \
		&all->temp, &all->temp);
	all->num[2] = mlx_xpm_file_to_image(all->mlx, "./sprite/number/two.xpm", \
		&all->temp, &all->temp);
	all->num[3] = mlx_xpm_file_to_image(all->mlx, "./sprite/number/three.xpm", \
		&all->temp, &all->temp);
	all->num[4] = mlx_xpm_file_to_image(all->mlx, "./sprite/number/four.xpm", \
		&all->temp, &all->temp);
	all->num[5] = mlx_xpm_file_to_image(all->mlx, "./sprite/number/five.xpm", \
		&all->temp, &all->temp);
	all->num[6] = mlx_xpm_file_to_image(all->mlx, "./sprite/number/six.xpm", \
		&all->temp, &all->temp);
	all->num[7] = mlx_xpm_file_to_image(all->mlx, "./sprite/number/seven.xpm", \
		&all->temp, &all->temp);
	all->num[8] = mlx_xpm_file_to_image(all->mlx, "./sprite/number/eight.xpm", \
		&all->temp, &all->temp);
	all->num[9] = mlx_xpm_file_to_image(all->mlx, "./sprite/number/nine.xpm", \
		&all->temp, &all->temp);
	return (init_sprite_bunny(all));
}

int	init_sprite_deco(t_data *all)
{
	all->deco[0] = mlx_xpm_file_to_image(all->mlx, "./sprite/deco/bush.xpm", \
		&all->temp, &all->temp);
	all->deco[1] = mlx_xpm_file_to_image(all->mlx, "./sprite/deco/flower.xpm", \
		&all->temp, &all->temp);
	all->deco[2] = mlx_xpm_file_to_image(all->mlx, "./sprite/deco/mush_1.xpm", \
		&all->temp, &all->temp);
	all->deco[3] = mlx_xpm_file_to_image(all->mlx, "./sprite/deco/mush_2.xpm", \
		&all->temp, &all->temp);
	all->deco[4] = mlx_xpm_file_to_image(all->mlx, "./sprite/deco/mush_3.xpm", \
		&all->temp, &all->temp);
	all->deco[5] = mlx_xpm_file_to_image(all->mlx, "./sprite/deco/rock.xpm", \
		&all->temp, &all->temp);
	all->deco[6] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/deco/tronc.xpm", &all->temp, &all->temp);
	all->deco[7] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/deco/sunflower.xpm", &all->temp, &all->temp);
	all->deco[8] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/deco/tree_down.xpm", &all->temp, &all->temp);
	all->deco[9] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/deco/cow_right_1.xpm", &all->temp, &all->temp);
	all->deco[10] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/deco/cow_right_2.xpm", &all->temp, &all->temp);
	return (check_image(all));
}

int	init_sprite_bunny(t_data *all)
{
	all->bunny[0] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/bunny/front_1.xpm", &all->temp, &all->temp);
	all->bunny[4] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/bunny/front_2.xpm", &all->temp, &all->temp);
	all->bunny[1] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/bunny/left_1.xpm", &all->temp, &all->temp);
	all->bunny[5] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/bunny/left_2.xpm", &all->temp, &all->temp);
	all->bunny[2] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/bunny/back_1.xpm", &all->temp, &all->temp);
	all->bunny[6] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/bunny/back_2.xpm", &all->temp, &all->temp);
	all->bunny[3] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/bunny/right_1.xpm", &all->temp, &all->temp);
	all->bunny[7] = mlx_xpm_file_to_image(all->mlx, \
		"./sprite/bunny/right_2.xpm", &all->temp, &all->temp);
	return (init_sprite_deco(all));
}

void	print_mov(t_data *all)
{
	char	*str;
	int		len;
	int		i;

	all->mov++;
	str = ft_itoa(all->mov);
	len = ft_strlen(str);
	i = 0;
	while (all->grid[0][i])
		mlx_put_image_to_window(all->mlx, all->win, all->grass, (i++) * 71, 0);
	i = 0;
	while (str[i])
	{
		mlx_put_image_to_window(all->mlx, all->win, all->num[str[i] - 48], \
			all->screen_x - (len * 44), 3);
		len--;
		i++;
	}
	free(str);
}

void	init_chick(t_data *all, int i, int j)
{
	t_chick	*temp;

	mlx_put_image_to_window(all->mlx, all->win, all->dirt, j * 71, i * 71);
	mlx_put_image_to_window(all->mlx, all->win, all->chick[0], \
		j * 71, i * 71);
	if (!all->chicks)
	{
		all->chicks = malloc(sizeof (t_chick));
		temp = all->chicks;
	}
	else
	{
		temp = all->chicks;
		while (all->chicks->next != NULL)
			all->chicks = all->chicks->next;
		all->chicks->next = malloc(sizeof (t_chick));
		all->chicks = all->chicks->next;
	}
	all->grid[i][j] = 'o';
	all->chicks->c_pos_x = i;
	all->chicks->c_pos_y = j;
	all->chicks->chick_state = 0;
	all->chicks->next = NULL;
	all->chicks = temp;
}
