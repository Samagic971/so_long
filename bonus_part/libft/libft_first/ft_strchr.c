/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:16:06 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 21:16:07 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			return (str);
		str++;
	}
	if ((unsigned char)*str == (unsigned char)c)
		return (str);
	return (0);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strchr("tripouille", 't' + 256));
// 	return (0);
// }
