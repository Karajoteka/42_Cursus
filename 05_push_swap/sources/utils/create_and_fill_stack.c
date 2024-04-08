/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_fill_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:17:51 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/23 17:52:06 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->pos = 0;
	node->target_pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

t_stack	*fill_stack_a(int *integers, int len)
{
	t_stack	*head;
	t_stack	*current;
	int		i;

	head = create_node(integers[0]);
	if (!head)
		return (NULL);
	current = head;
	i = 1;
	while (i < len)
	{
		current->next = create_node(integers[i]);
		if (!current->next)
		{
			free_stack(head);
			return (NULL);
		}
		current = current->next;
		i++;
	}
	return (head);
}
