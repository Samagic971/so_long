/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:05:06 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/05 20:05:08 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*res;
	size_t			count;

	count = 0;
	res = malloc(n * size);
	if (n == 0 || size == 0 || !res)
		return (res);
	while (count < n * size)
	{
		res[count] = 0;
		count++;
	}
	return (res);
}
