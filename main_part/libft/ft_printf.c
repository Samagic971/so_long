/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:05:08 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/22 12:13:53 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_var(const char *str, va_list arg)
{
	int	i;

	i = 0;
	if (*(str + 1) == 'c')
		ft_putchar_fd(va_arg(arg, int), ++i);
	else if (*(str + 1) == '%')
		ft_putchar_fd('%', ++i);
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		ft_print_num(va_arg(arg, int), &i, 0);
	else if (*(str + 1) == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (*(str + 1) == 'x' || *(str + 1) == 'X')
		print_hex(va_arg(arg, unsigned int), ((*(str + 1) - 88) % 31), &i, 0);
	else if (*(str + 1) == 'p')
	{
		i += ft_putstr("0x");
		print_hex(va_arg(arg, unsigned long), 1, &i, 0);
	}
	else if (*(str + 1) == 'u')
		ft_print_num(va_arg(arg, unsigned int), &i, 0);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;

	i = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			i += ft_var(str, arg);
			str += 2;
		}
		else
		{
			write(1, str++, 1);
			i++;
		}
	}
	va_end(arg);
	return (i);
}

// int	main(void)
// {
// 	ft_printf("%d", -2147483648);
// 	return (0);
// }
