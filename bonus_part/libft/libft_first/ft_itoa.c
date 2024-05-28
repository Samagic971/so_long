/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:45:22 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/06 18:45:24 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs_val(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}

char	*ft_itoa(int n)
{
	int		temp;
	int		len;
	char	*res;

	len = -1;
	temp = n;
	while (len++, temp != 0)
		temp /= 10;
	if (n <= 0)
		len += 1;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[len - 1] = ft_abs_val(n % 10) + '0';
		n /= 10;
		len--;
	}
	return (res);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(123));
// 	printf("%s\n", ft_itoa(-123));
// 	printf("%s\n", ft_itoa(-0123));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-0));
// 	printf("%s\n", ft_itoa(2147483647));
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return (0);
// }
