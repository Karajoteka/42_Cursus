/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_elements_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:23:45 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/27 19:32:36 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_elements_to_b_first_half(t_stack **stack_a, t_stack **stack_b,
		int largest_index[3], int mid_index)
{
	int	i;
	int	len;

	len = stack_length(*stack_a);
	i = 0;
	while (i < len && stack_length(*stack_a) != 3)
	{
		if ((*stack_a)->index <= mid_index
			&& (*stack_a)->index != largest_index[0]
			&& (*stack_a)->index != largest_index[1]
			&& (*stack_a)->index != largest_index[2])
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a);
		i++;
	}
}

void	move_elements_to_b_second_half(t_stack **stack_a, t_stack **stack_b,
		int largest_index[3], int mid_index)
{
	int	i;
	int	len;

	len = stack_length(*stack_a);
	i = 0;
	while (i < len && stack_length(*stack_a) != 3)
	{
		if ((*stack_a)->index > mid_index
			&& (*stack_a)->index != largest_index[0]
			&& (*stack_a)->index != largest_index[1]
			&& (*stack_a)->index != largest_index[2])
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a);
		i++;
	}
}

void	move_elements_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	largest_index[3];
	int	mid_index;

	find_three_largest_index(stack_a, largest_index);
	mid_index = stack_length(*stack_a) / 2;
	move_elements_to_b_first_half(stack_a, stack_b, largest_index, mid_index);
	move_elements_to_b_second_half(stack_a, stack_b, largest_index, mid_index);
	while (stack_length(*stack_a) > 3)
		do_pb(stack_a, stack_b);
}
