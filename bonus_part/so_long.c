/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:30:17 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/26 20:00:36 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	voidvoid(void)
{
	mlx_init();
	return ;
}

int	main(int ac, char *av[])
{
	t_data	all;

	all.grid = NULL;
	if (ac < 2)
		return (0);
	all.grid = create_array(av[1], &all);
	if (!all.grid)
		return (0);
	if (valid_grid(&all) == 0)
	{
		free_array(all.grid);
		return (0);
	}
	launch(&all);
	return (0);
}
