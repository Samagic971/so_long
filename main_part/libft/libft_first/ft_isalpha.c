/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:53:26 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 15:53:26 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c < 65 || c > 90) && (c < 97 || c > 122))
	{
		return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	printf("%d\n", isalpha(0));
// 	printf("%d\n", ft_isalpha(0));
// 	printf("%d\n", isalpha(48));
// 	printf("%d", ft_isalpha(48));
// 	return (0);
// }
