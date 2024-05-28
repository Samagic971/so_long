/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:10:56 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/27 16:10:57 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	is_it_rect(char **array)
{
	int		i;
	size_t	size;

	i = 1;
	size = ft_strlen(array[0]);
	while (array[i])
		if (ft_strlen(array[i++]) != size)
			return (0);
	if (i == 2)
		return (0);
	return (1);
}

int	wall_ok(char **array)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (array[0][y + 1])
		if (array[0][y++] != '1')
			return (0);
	y = 0;
	while (array[i + 1] && array[i][y + 1])
	{
		if (array[i][y] != '1' && (y == 0 || array[i][y + 2] == '\0'))
			return (0);
		if (array[i][y + 2] == '\0')
		{
			y = 0;
			i++;
		}
		else
			y++;
	}
	while (array[i][y + 1])
		if (array[i][y++] != '1')
			return (0);
	return (1);
}

int	is_thr_this(char **array, char element)
{
	int	i;
	int	y;
	int	count;

	i = 0;
	count = 0;
	while (array[i])
	{
		y = 0;
		while (array[i][y])
			if (array[i][y++] == element)
				count++;
		i++;
	}
	return (count);
}

int	valid_grid(t_data *all)
{
	int	i;
	int	y;

	if (!valid_element(all->grid))
	{
		ft_putendl_fd("Umknow symbol, or no new line in the end.", 2);
		return (0);
	}
	i = f_p(all->grid, 'P', 'i');
	y = f_p(all->grid, 'P', 'y');
	if (i != -1 && all->grid[i][y] == 'P')
		parse_grid(all->grid, i, y);
	all->coll = is_thr_this(all->grid, 'c');
	if (!is_it_rect(all->grid) || is_thr_this(all->grid, 'e') != 1 || \
		is_thr_this(all->grid, 'P') != 1 || is_thr_this(all->grid, 'c') < 1 \
		|| is_thr_this(all->grid, 'C') > 0 || is_thr_this(all->grid, 'E') > 0)
		ft_putendl_fd(PROB_GRID, 2);
	else if (!wall_ok(all->grid))
		ft_putendl_fd("Problem with wall", 2);
	else
		return (1);
	return (0);
}
