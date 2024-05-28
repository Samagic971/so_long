/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:22:48 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/06 19:22:49 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	count;

	count = 0;
	res = malloc((1 + ft_strlen(s) * sizeof(char)));
	if (!res)
		return (0);
	while (s[count])
	{
		res[count] = (*f)(count, s[count]);
		count++;
	}
	res[count] = '\0';
	return (res);
}
