/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:53:22 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 15:53:22 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", isalnum(0));
// 	printf("%d\n", ft_isalnum(0));
// 	printf("%d\n", isalnum(48));
// 	printf("%d", ft_isalnum(48));
// 	return (0);
// }
