/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:00:24 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/06 20:00:26 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd2(int n, int fd)
{
	int	temp;

	if (n > 0)
	{
		temp = (n % 10) + '0';
		ft_putnbr_fd2(n /= 10, fd);
		ft_putchar_fd(temp, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	temp;

	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		temp = (-(n % 10)) + '0';
		ft_putnbr_fd2(n /= -10, fd);
		ft_putchar_fd(temp, fd);
	}
	else
	{
		temp = (n % 10) + '0';
		ft_putnbr_fd2(n /= 10, fd);
		ft_putchar_fd(temp, fd);
	}
}

// int	main(void)
// {
// 	ft_putnbr_fd(42, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-42, 1);
// 	printf("\n");
// 	ft_putnbr_fd(0, 1);
// 	printf("\n");
// 	ft_putnbr_fd(2147483647, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-2147483648, 1);
// }
