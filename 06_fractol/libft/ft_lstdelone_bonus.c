/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:51:40 by aorcha-m          #+#    #+#             */
/*   Updated: 2023/12/09 12:58:41 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Take a node 'lst' as a parameter and free the memory of its content using 
   the 'del' function provided as a parameter, in addition to freeing the node.
   The memory of 'next' should not be freed. */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
