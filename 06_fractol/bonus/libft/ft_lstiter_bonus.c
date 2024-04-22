/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:27:11 by aorcha-m          #+#    #+#             */
/*   Updated: 2023/12/09 12:59:32 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterate through the list 'lst' and apply the function 'f' to the content 
   of each node. */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
