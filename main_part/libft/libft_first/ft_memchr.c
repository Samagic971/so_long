/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:52:32 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/05 15:52:34 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	return (0);
}

// int	main(void)
// {
// 	int	test[] = {0, 1, 2 ,3 ,4 ,5};

// 	ft_memchr(test, 2, 3);
// 	// printf("%d\n", ft_memchr(test, 2, 3));
// 	return (0);
// }
