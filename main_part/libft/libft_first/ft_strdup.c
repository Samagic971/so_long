/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:31:35 by sastier-          #+#    #+#             */
/*   Updated: 2024/02/06 19:31:41 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	int		count;
	char	*dest;

	count = 0;
	while (src[count])
		count++;
	dest = malloc((count + 1) * sizeof(char));
	if (dest == NULL)
		return (dest);
	count = 0;
	while (src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

// int	main(int argc, char *argv[])
// {
// 	printf("New string : %s\n", ft_strdup(argv[1]));
// 	return (argc);
// }
