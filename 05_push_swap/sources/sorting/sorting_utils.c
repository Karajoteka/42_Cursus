/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:25:55 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/27 17:41:45 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *head)
{
	t_stack	*current;

	current = head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	free_stack(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	stack_length(t_stack *head)
{
	t_stack	*current;
	int		len;

	current = head;
	len = 0;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}
