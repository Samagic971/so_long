/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:30:27 by sastier-          #+#    #+#             */
/*   Updated: 2024/04/26 20:01:50 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx.h"
# include "libft/ft_printf.h"
# define PROB_GRID "Problem with grid (Number of smth or not rectangle)\
 or path not valid"

typedef struct s_data
{
	void	*mlx;
	void	*win;

	char	**grid;
	int		width_grid;
	int		length_grid;

	void	*front;
	void	*back;
	void	*left;
	void	*right;
	void	*dirt;
	void	*grass;
	void	*collect;
	void	*exit;
	int		temp;

	int		mov;
	int		coll;

//Pas sur de a quoi ca sert, a voir si c'est important
	// char	*addr;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;
	int		screen_x;
	int		screen_y;
	int		pos_x;
	int		pos_y;
}			t_data;

char	**create_array(char *file, t_data *all);

//verif_aray.c 		Verif grid + free if problem;
void	parse_grid(char **array, int i, int y);
int		valid_grid(t_data *all);
void	free_array(char **array);
int		f_p(char **array, char c, char axis);
int		valid_element(char **array);

//utils.c
void	ft_print_array(char **array);

//graphics.c
void	launch(t_data *all);
int		hook_event(int keydown, t_data *all);
void	close_window(t_data *all);

#endif
