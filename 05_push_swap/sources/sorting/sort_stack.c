/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:25 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/30 09:16:05 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stack_over_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_cost_element;

	min_cost_element = NULL;
	move_elements_to_b(stack_a, stack_b);
	sort_three(stack_a);
	assign_positions(stack_a, stack_b);
	assign_target_pos(stack_a, stack_b);
	calculate_costs(stack_a, stack_b);
	while (*stack_b)
	{
		min_cost_element = get_low_cost(*stack_b);
		execute_actions(stack_a, stack_b, min_cost_element);
		assign_positions(stack_a, stack_b);
		assign_target_pos(stack_a, stack_b);
		calculate_costs(stack_a, stack_b);
	}
	calculate_costs(stack_b, stack_a);
	rotate_to_right_position(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first > third)
		do_ra(stack_a);
	if (second > first && second > third)
		do_rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		do_sa(stack_a);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	if (is_sorted(*stack_a))
		return ;
	len = stack_length(*stack_a);
	if (len == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (len == 3 && !is_sorted(*stack_a))
		sort_three(stack_a);
	else if (len > 3)
		sort_stack_over_five(stack_a, stack_b);
}
