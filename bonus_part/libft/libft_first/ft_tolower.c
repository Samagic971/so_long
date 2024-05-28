/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:12:04 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 21:12:06 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

// int	main(void)
// {
// 	printf("%c\n", ft_lower(64));
// 	printf("%c\n", ft_lower(65));
// 	printf("%c\n", ft_lower(90));
// 	return (0);
// }
