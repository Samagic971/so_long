/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:08:53 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 21:08:55 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}

// int	main(void)
// {
// 	printf("%c\n", ft_toupper(96));
// 	printf("%c\n", ft_toupper(97));
// 	printf("%c\n", ft_toupper(122));
// 	return (0);
// }
