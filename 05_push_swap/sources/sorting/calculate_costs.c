/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:23:50 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/23 17:50:17 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*get_low_cost(t_stack *stack_b)
{
	t_stack	*temp_b;
	int		total_cost;
	int		min_cost;
	t_stack	*min_cost_element;

	min_cost = INT_MAX;
	min_cost_element = NULL;
	temp_b = stack_b;
	while (temp_b)
	{
		total_cost = ft_abs(temp_b->cost_a) + ft_abs(temp_b->cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			min_cost_element = temp_b;
		}
		temp_b = temp_b->next;
	}
	return (min_cost_element);
}

int	calculate_cost(int position, int len)
{
	int	middle;

	middle = len / 2;
	if (position < middle)
		return (position);
	else
		return (position - len);
}

void	calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	int		len_a;
	int		len_b;

	len_a = stack_length(*stack_a);
	len_b = stack_length(*stack_b);
	temp_b = *stack_b;
	while (temp_b)
	{
		temp_b->cost_b = calculate_cost(temp_b->pos, len_b);
		temp_b->cost_a = calculate_cost(temp_b->target_pos, len_a);
		temp_b = temp_b->next;
	}
}
