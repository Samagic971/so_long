/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:05:05 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/22 12:12:08 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(long numb, int *i, int rep)
{
	if (numb < 0)
	{
		ft_putchar_fd('-', 1);
		(*i)++;
		numb = -numb;
	}
	if (rep == 0 && numb == 0)
	{
		ft_putchar_fd('0', 1);
		(*i)++;
	}
	if (numb > 0)
	{
		ft_print_num(numb / 10, i, 1);
		ft_putnbr_fd(numb % 10, 1);
		(*i)++;
	}
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	while (*s)
	{
		ft_putchar_fd(*s++, 1);
		i++;
	}
	return (i);
}

void	print_hex(unsigned long num, int cap, int *i, int rep)
{
	char			*val;

	val = "0123456789ABCDEF0123456789abcdef";
	if (rep == 0 && num == 0)
	{
		ft_putchar_fd('0', 1);
		(*i)++;
	}
	if (num != 0)
	{
		print_hex(num / 16, cap, i, 1);
		ft_putchar_fd(val[(num % 16) + 16 * cap], 1);
		(*i)++;
	}
}
