/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:46:23 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/27 17:46:24 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// To find the position of element 'c' in double array 'array'. Can return x 
// coordonates or y depending on 'axis'
int	f_p(char **array, char c, char axis)
{
	int	i;
	int	y;

	i = 0;
	while (array[i])
	{
		y = 0;
		while (array[i][y])
		{
			if (array[i][y] == c)
				break ;
			y++;
		}
		if (array[i][y] == c)
			break ;
		i++;
	}
	if (!array[i][y])
		return (-1);
	if (axis == 'i')
		return (i);
	return (y);
}

int	valid_element(char **array)
{
	int	i;
	int	y;

	i = 0;
	while (array[i])
	{
		y = 0;
		while (array[i][y + 1])
			if (!ft_strchr("PCE01", array[i][y++]))
				return (0);
		if (array[i++][y] != '\n')
			return (0);
	}
	return (1);
}

void	parse_grid(char **array, int i, int y)
{
	if (array[i][y] == 'C')
		array[i][y] = 'c';
	else if (array[i][y] == 'E')
		array[i][y] = 'e';
	else if (array[i][y] == '0')
		array[i][y] = 'o';
	if (i - 1 > 0 && ft_strchr("CE0", array[i - 1][y]))
		parse_grid(array, i - 1, y);
	if (y - 1 > 0 && ft_strchr("CE0", array[i][y - 1]))
		parse_grid(array, i, y - 1);
	if (ft_strchr("CE0", array[i][y + 1]))
		parse_grid(array, i, y + 1);
	if (array[i + 1] && ft_strchr("CE0", array[i + 1][y]))
		parse_grid(array, i + 1, y);
}
