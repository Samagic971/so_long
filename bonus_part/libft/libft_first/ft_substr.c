/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:31:40 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/05 20:31:42 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL || !s)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	const char	*str;
// 	char		*res;

// 	str = "We want some of thi";
// 	res = ft_substr(str, 8, 0);
// 	printf("%s\n", res);
// 	return (0);
// }
