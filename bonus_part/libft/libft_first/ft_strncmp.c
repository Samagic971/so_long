/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:42:44 by sastier-          #+#    #+#             */
/*   Updated: 2024/01/28 19:42:46 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (s1[count] && count < n)
	{
		if (s1[count] != s2[count])
		{
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		}
		count++;
	}
	if (s1[count] != s2[count] && count < n)
	{
		return ((unsigned char)s1[count] - (unsigned char)s2[count]);
	}
	return (0);
}

// int	main(void)
// {
// 	char	str1[] = "\x12\xff\x65\x12\xbd\xde\xad";
// 	char	str2[] = "\x12\x02";

// 	printf("%d\n", ft_strncmp(str1, str2, 6));
// 	printf("%d\n", strncmp(str1, str2, 6));
// 	return (0);
// }