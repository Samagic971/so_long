/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:21:00 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/06 12:21:02 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	if (end < start)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && s1[end])
		end--;
	res = malloc((end - start + 2) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + start, end - start + 2);
	return (res);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("ahlolh", "lha"));
// 	return (0);
// }
