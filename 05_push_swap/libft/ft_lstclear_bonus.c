/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:59:03 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/30 09:17:03 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Delete and free the given node 'lst' and all subsequent nodes,
	using the 'del'
   function and free(3). In the end, the pointer to the list should be NULL. */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
