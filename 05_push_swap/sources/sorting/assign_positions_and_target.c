/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_positions_and_target.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:47:12 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/23 17:47:56 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	assign_positions(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		position;

	temp = *stack_a;
	position = 0;
	while (temp)
	{
		temp->pos = position;
		position++;
		temp = temp->next;
	}
	temp = *stack_b;
	position = 0;
	while (temp)
	{
		temp->pos = position;
		position++;
		temp = temp->next;
	}
}

void	assign_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	t_stack	*temp_a;
	t_stack	*closest;

	temp_b = *stack_b;
	while (temp_b)
	{
		closest = NULL;
		temp_a = *stack_a;
		while (temp_a)
		{
			if (temp_a->index > temp_b->index && (closest == NULL
					|| temp_a->index < closest->index))
				closest = temp_a;
			temp_a = temp_a->next;
		}
		if (closest != NULL)
			temp_b->target_pos = closest->pos;
		temp_b = temp_b->next;
	}
}
