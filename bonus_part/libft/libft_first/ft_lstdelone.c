/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sastier- <sastier-@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:27:33 by sastier-          #+#    #+#             */
/*   Updated: 2024/03/07 14:27:34 by sastier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}

// int	main(void)
// {
// 	t_list	*test;

// 	test->content = 5;
// 	test->next = (t_list *)malloc(sizeof(t_list));
// 	test->next->content = 3;
// 	test->next->next = NULL;
// 	ft_lstdelone(test, )
// }
