/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:25:39 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/05 15:25:40 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		count;
	int		i;

	str = (char *)s;
	count = 0;
	i = -1;
	while (str[count])
	{
		if ((unsigned char)str[count] == (unsigned char)c)
			i = count;
		count++;
	}
	if ((unsigned char)str[count] == (unsigned char)c)
		return (&(str[count]));
	if (i != -1)
		return (&(str[i]));
	return (0);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strchr("tripouille", 't' + 256));
// 	return (0);
// }
