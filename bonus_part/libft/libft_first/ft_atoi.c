/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:29:00 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/05 19:29:02 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		count;
	int		res;
	int		neg;

	count = 0;
	res = 0;
	neg = 1;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == ' ')
	{
		count++;
	}
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			neg *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		res *= 10;
		res += str[count] - 48;
		count++;
	}
	return (res * neg);
}

// int	main(int argc, char *argv[])
// {
// 	if (argc > 1)
// 		printf("Res : %d\n", ft_atoi(argv[1]));
// 	return (argc);
// }
