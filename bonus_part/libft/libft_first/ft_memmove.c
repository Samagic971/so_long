/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:31:16 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 17:58:32 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*temp;
	const unsigned char	*temp_src;

	count = 0;
	temp = dest;
	temp_src = src;
	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		while (n - count++ > 0)
			temp[n - count] = temp_src[n - count];
	}
	else
	{
		while (count < n)
		{
			temp[count] = temp_src[count];
			count++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	a[] = "Test 1";
// 	char	b[20];

// 	ft_memmove(b, a, 5);
// 	return (0);
// }
