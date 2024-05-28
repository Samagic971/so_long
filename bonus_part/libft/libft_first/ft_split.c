/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:08:53 by sastier-          #+#    #+#             */
/*   Updated: 2024/02/08 16:08:55 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(const char *str, char sep)
{
	int		word;
	int		i;

	word = 0;
	i = 0;
	while (str[i])
	{
		while (sep == str[i] && str[i])
			i++;
		if (str[i] != '\0')
			word++;
		while (sep != str[i] && str[i])
			i++;
	}
	return (word);
}

static void	fill_split(char **res, const char *str, char c)
{
	int		i;
	int		j;
	int		pos;

	j = 0;
	i = 0;
	pos = 0;
	while (str[i])
	{
		if (c == str[i])
			i++;
		else
		{
			j = 0;
			while (c != str[i + j] && str[i + j])
				j++;
			res[pos] = (char *)malloc(sizeof(char) * (j + 1));
			ft_strlcpy(res[pos], str + i, j + 1);
			i += j;
			pos++;
		}
	}
}

char	**ft_split(char const *str, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * (countword(str, c) + 2));
	if (!result)
		return (0);
	result[countword(str, c) + 1] = 0;
	fill_split(result + 1, str, c);
	return (result);
}

// int	main(int ac, char *argv[])
// {
// 	int		count;
// 	char	**str;

// 	count = 0;
// 	if (ac == 1)
// 		return (0);
// 	str = ft_split(argv[1], 'l');
// 	while (str[count])
// 	{
// 		printf("%s,\n", str[count]);
// 		count++;
// 	}
// 	return (ac);
// }
