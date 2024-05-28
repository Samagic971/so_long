/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:53:40 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 15:53:40 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			count;

	ptr = s;
	count = 0;
	while (count < n)
	{
		(*ptr++) = (unsigned char)c;
		count++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	s[18];

// 	printf("%p\n", memset(s, 48, 5));
// 	printf("%p\n", ft_memset(s, 48, 5));
// 	return (0);
// }
