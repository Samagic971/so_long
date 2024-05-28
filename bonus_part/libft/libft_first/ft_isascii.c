/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:53:29 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 15:53:29 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
	{
		return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	printf("%d\n", isascii(150));
// 	printf("%d\n", ft_isascii(150));
// 	printf("%d\n", isascii(18));
// 	printf("%d", ft_isascii(18));
// 	return (0);
// }
