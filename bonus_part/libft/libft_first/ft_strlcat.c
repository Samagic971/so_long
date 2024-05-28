/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:23:20 by sastier-          #+#    #+#             */
/*   Updated: 2024/01/29 16:23:24 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;

	i = 0;
	len_dest = ft_strlen(dest);
	while ((size > len_dest + i + 1) && src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	i = ft_strlen(src);
	if (len_dest < size)
		return (len_dest + i);
	return (size + i);
}

// int	main(void)
// {
// 	char	str[] = "xyz";
// 	char	str2[20] = "aaaa";
// 	char	str3[] = "xyz";
// 	char	str4[20] = "aaaa";
// 	int		a;
// 	int		size;

// 	size = 14;
// 	a = ft_strlcat(str2, str, size);
// 	printf("%d, %s\n", a, str2);
// 	a = strlcat(str4, str3, size);
// 	printf("%d, %s\n", a, str4);
// 	return (0);
// }
