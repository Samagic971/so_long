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
# include <time.h>
# define PROB_GRID "Problem with grid (Number of smth or not rectangle)\
 or path not valid"

typedef struct s_chick
{
	int				c_pos_x;
	int				c_pos_y;
	int				chick_state;
	struct s_chick	*next;
}					t_chick;

typedef struct s_data
{
	void			*mlx;
	void			*win;

	char			**grid;
	int				width_grid;
	int				length_grid;

	int				game_state;

	void			*bunny[8];
	void			*chick[4];
	void			*dirt;
	void			*grass;
	void			*collect[2];
	void			*exit;
	void			*num[10];
	void			*deco[11];
	void			*wallpaper;
	int				temp;

	int				mov;
	int				coll;

	long			frame;
//Pas sur de a quoi ca sert, a voir si c'est important
	// char	*addr;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;
	int				screen_x;
	int				screen_y;

	//pos of player
	int				pos_x;
	int				pos_y;
	int				bunny_state;

	//pos of chick
	t_chick			*chicks;
}					t_data;

char	**create_array(char *file, t_data *all);

//verif_aray.c 		Verif grid + free if problem;
void	parse_grid(char **array, int i, int y);
int		valid_grid(t_data *all);
void	free_array(char **array);
int		f_p(char **array, char c, char axis);
int		valid_element(char **array);

//utils.c
void	ft_print_array(char **array);

void	draw_in_grass(t_data *all, int i, int j);

//graphics.c
void	launch(t_data *all);
int		hook_event(int keydown, t_data *all);
void	close_window(t_data *all);
int		init_sprite_num(t_data *all);
int		check_image(t_data *all);
void	print_mov(t_data *all);
void	print_bunny(t_data *all, void *img);

int		update_win(t_data *all);
void	init_chick(t_data *all, int i, int j);
void	update_chick(t_data *all);
void	print_chick(t_data *all, void *img, t_chick *chick);
int		is_there_chick(t_chick *chick, t_data *all, int x, int y);

void	end_screen(int keydown, t_data *all);

#endif
