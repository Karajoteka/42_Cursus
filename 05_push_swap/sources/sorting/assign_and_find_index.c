/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_and_find_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:44:58 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/27 17:20:57 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	assign_index(t_stack *head)
{
	t_stack	*current;
	t_stack	*comparison_node;
	int		index;
	int		min_value;

	current = head;
	while (current)
	{
		comparison_node = head;
		index = 1;
		min_value = current->value;
		while (comparison_node)
		{
			if (comparison_node->value < min_value)
				index++;
			comparison_node = comparison_node->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	find_three_largest_index(t_stack **stack, int *largest_indices)
{
	t_stack	*temp;

	largest_indices[0] = INT_MIN;
	largest_indices[1] = INT_MIN;
	largest_indices[2] = INT_MIN;
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->index > largest_indices[0])
		{
			largest_indices[2] = largest_indices[1];
			largest_indices[1] = largest_indices[0];
			largest_indices[0] = temp->index;
		}
		else if (temp->index > largest_indices[1])
		{
			largest_indices[2] = largest_indices[1];
			largest_indices[1] = temp->index;
		}
		else if (temp->index > largest_indices[2])
			largest_indices[2] = temp->index;
		temp = temp->next;
	}
}

void	find_two_smallest_index(t_stack **stack, int *smallest_indices)
{
	t_stack	*temp;

	smallest_indices[0] = INT_MAX;
	smallest_indices[1] = INT_MAX;
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->index < smallest_indices[0])
		{
			smallest_indices[1] = smallest_indices[0];
			smallest_indices[0] = temp->index;
		}
		else if (temp->index < smallest_indices[1])
		{
			smallest_indices[1] = temp->index;
		}
		temp = temp->next;
	}
}
