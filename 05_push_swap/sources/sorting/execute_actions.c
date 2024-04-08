/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:38:55 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/27 19:34:56 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_to_right_position(t_stack **stack_a)
{
	t_stack	*min_index_element;
	t_stack	*current;
	int		index;
	int		len;

	min_index_element = *stack_a;
	current = (*stack_a)->next;
	while (current != NULL)
	{
		if (current->index < min_index_element->index)
			min_index_element = current;
		current = current->next;
	}
	index = min_index_element->index;
	len = stack_length(*stack_a);
	if ((*stack_a)->cost_b > 0)
	{
		while ((*stack_a)->index != index)
			do_ra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != index)
			do_rra(stack_a);
	}
}

void	execute_actions_a(t_stack **stack_a, t_stack *min_cost_element)
{
	while (min_cost_element->cost_a != 0)
	{
		if (min_cost_element->cost_a > 0)
		{
			do_ra(stack_a);
			min_cost_element->cost_a--;
		}
		else if (min_cost_element->cost_a < 0)
		{
			do_rra(stack_a);
			min_cost_element->cost_a++;
		}
	}
}

void	execute_actions_b(t_stack **stack_b, t_stack *min_cost_element)
{
	while (min_cost_element->cost_b != 0)
	{
		if (min_cost_element->cost_b > 0)
		{
			do_rb(stack_b);
			min_cost_element->cost_b--;
		}
		else if (min_cost_element->cost_b < 0)
		{
			do_rrb(stack_b);
			min_cost_element->cost_b++;
		}
	}
}

void	execute_actions(t_stack **stack_a, t_stack **stack_b,
		t_stack *min_cost_element)
{
	while (min_cost_element->cost_a != 0 || min_cost_element->cost_b != 0)
	{
		if (min_cost_element->cost_a > 0 && min_cost_element->cost_b > 0)
		{
			do_rr(stack_a, stack_b);
			min_cost_element->cost_a--;
			min_cost_element->cost_b--;
		}
		else if (min_cost_element->cost_a < 0 && min_cost_element->cost_b < 0)
		{
			do_rrr(stack_a, stack_b);
			min_cost_element->cost_a++;
			min_cost_element->cost_b++;
		}
		else
		{
			execute_actions_a(stack_a, min_cost_element);
			execute_actions_b(stack_b, min_cost_element);
		}
	}
	do_pa(stack_a, stack_b);
}
