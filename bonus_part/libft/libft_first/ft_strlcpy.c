/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:34:31 by sastier-          #+#    #+#             */
/*   Updated: 2024/01/28 18:34:33 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 1;
	while (src[count - 1] && count < size)
	{
		dest[count - 1] = src[count - 1];
		count++;
	}
	if (size != 0)
		dest[count - 1] = '\0';
	while (src[count - 1])
	{
		count++;
	}
	return (count - 1);
}

// int	main(void)
// {
// 	char	str1[] = "abcdefgh123456789";
// 	char	str2[27] = "pppppppppppp";
// 	char	str3[] = "abcdefgh123456789";
// 	char	str4[27] = "pppppppppppp";
// 	int		a;

// 	a = ft_strlcpy(str2, str1, 2);
// 	printf("%s, %d\n", str2, a);
// 	a = strlcpy(str4, str3, 2);
// 	printf("%s, %d\n", str4, a);
// 	return (0);
// }
