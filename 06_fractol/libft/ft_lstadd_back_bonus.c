/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:45:57 by aorcha-m          #+#    #+#             */
/*   Updated: 2023/12/09 12:55:16 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Add the node 'new' to the end of the list 'lst'. */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = *lst;
			while (last->next != NULL)
				last = last->next;
			last->next = new;
		}
	}
}
