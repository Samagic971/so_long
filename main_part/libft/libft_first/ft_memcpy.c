/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:10:43 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 16:32:07 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if (!dest && !src)
		return (0);
	while (count < n)
	{
		((unsigned char *)dest)[count] = ((unsigned char *)src)[count];
		count++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	a[] = "Test 1";
// 	char	b[20];

// 	ft_memcpy(a, b, 1);
// 	return (0);
// }
