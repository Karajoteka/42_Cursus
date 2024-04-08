/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:03:26 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/25 15:09:36 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_stack *head, char stack_name, t_stack *min_cost_element)
{
	t_stack	*current;

	current = head;
	ft_printf("Stack %c\n", stack_name);
	if (stack_name == 'A')
		ft_printf("VALUE	INDEX	POS\n");
	else
		ft_printf("VALUE	INDEX	POS	TARGET	COST_B	COST_A\n");
	while (current)
	{
		ft_printf("%d	%d	%d", current->value, current->index, current->pos);
		if (stack_name == 'B')
		{
			ft_printf("	%d	%d	%d", current->target_pos, current->cost_b,
				current->cost_a);
			if (current == min_cost_element)
				ft_printf(" <- Minimum total cost");
		}
		ft_printf("\n");
		current = current->next;
	}
}
