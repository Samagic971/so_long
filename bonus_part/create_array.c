/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:59:38 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/27 12:59:41 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_file(char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i])
		i++;
	if (i < 5)
	{
		ft_putendl_fd("Wrong extension/name", 2);
		return (0);
	}
	if (ft_strncmp(".ber", file + i - 4, 5))
	{
		ft_putendl_fd("Wrong extension/name", 2);
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (read(fd, 0, 0) == -1 || fd < 0)
	{
		close(fd);
		ft_putendl_fd("Nothing to read", 2);
		return (0);
	}
	close(fd);
	return (-1);
}

int	num_line(char *file)
{
	char	*buff;
	int		fd;
	int		size;

	size = 0;
	fd = open(file, O_RDONLY);
	buff = get_next_line(fd);
	while (buff)
	{
		size++;
		free(buff);
		buff = get_next_line(fd);
	}
	close(fd);
	return (size);
}

char	**create_array(char *file, t_data *all)
{
	char	**array;
	int		fd;
	int		i;
	int		size;

	i = 0;
	if (verif_file(file) == 0)
		return (NULL);
	size = num_line(file);
	array = malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (i < size)
		array[i++] = get_next_line(fd);
	array[i] = NULL;
	close(fd);
	all->width_grid = i;
	all->length_grid = ft_strlen(array[0]) - 1;
	return (array);
}
