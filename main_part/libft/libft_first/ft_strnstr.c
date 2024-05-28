/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:16:24 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/05 17:16:26 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_needle(char *str, char *to_find, size_t len)
{
	size_t	count;

	count = 0;
	while (str[count] == to_find[count] && len > count && str[count])
		count++;
	if (to_find[count] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	count;
	char	*haystack;
	char	*needle;

	count = 0;
	haystack = (char *)str;
	needle = (char *)to_find;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[count] && len > count)
	{
		if (haystack[count] == needle[0])
		{
			if (ft_is_needle(&(haystack[count]), needle, len - count) == 1)
				return (&haystack[count]);
		}
		count++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str1[] = "loremlorem ipsum sit lador";
// 	char	str2[] = "";

// 	printf("%s", ft_strnstr(str1, str2, 15));
// 	return (0);
// }
