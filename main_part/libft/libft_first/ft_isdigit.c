/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:53:33 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 15:53:33 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
	{
		return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	printf("%d\n", isdigit(0));
// 	printf("%d\n", ft_isdigit(0));
// 	printf("%d\n", isdigit(48));
// 	printf("%d", ft_isdigit(48));
// 	return (0);
// }
