/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:53:36 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 15:53:37 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
	{
		return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	printf("%d\n", isprint(126));
// 	printf("%d\n", ft_isprint(126));
// 	printf("%d\n", isprint(127));
// 	printf("%d", ft_isprint(127));
// 	return (0);
// }
