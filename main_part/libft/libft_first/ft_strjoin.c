/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:36:47 by sastier-          #+#    #+#             */
/*   Updated: 2024/02/07 17:36:48 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (res);
}

// int	main(int argc, char *argv[])
// {
// 	char	*result;

// 	argv++;
// 	if (argc > 2)
// 	{
// 		result = ft_strjoin("Bonjour", "A toi"); //argv[1], argv[2]);
// 		printf("String is : %s", result);
// 	}
// 	return (argc);
// }
