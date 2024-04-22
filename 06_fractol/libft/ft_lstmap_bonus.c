/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:25:24 by aorcha-m          #+#    #+#             */
/*   Updated: 2023/12/09 13:01:25 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterate through the list 'lst' and apply the function 'f' to the content 
   of each node. Create a resulting list from the correct and successive 
   application of the function 'f' on each node. The 'del' function is used 
   to delete the content of a node, if necessary. */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	**last_ptr;
	t_list	*new_node;

	new_list = NULL;
	last_ptr = &new_list;
	while (lst)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		new_node->next = NULL;
		*last_ptr = new_node;
		last_ptr = &new_node->next;
		lst = lst->next;
	}
	return (new_list);
}
