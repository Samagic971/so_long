/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:05:12 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/22 12:12:25 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft_first/libft.h"
# include "get_next_line/get_next_line.h"

int		ft_printf(const char *str, ...);
int		ft_var(const char *str, va_list arg);
int		ft_putstr(char *s);
int		ft_var(const char *str, va_list arg);
void	ft_print_num(long numb, int *i, int rep);
void	print_hex(unsigned long num, int cap, int *i, int rep);

#endif