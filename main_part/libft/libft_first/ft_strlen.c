/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:53:44 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/04 15:54:58 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

/*
int	main(void)
{
	char	str[] = "Salut !";
	char	str2[] = "Hello World <3";	
	int		a;

	a = ft_strlen(str);
	printf("Mot : '%s', taille : %d\n", str, a);
	a = ft_strlen(str2);
	printf("Mot 2 : '%s', taille : %d", str2, a);
	return (a);
}
*/
