/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:20:26 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/30 09:15:43 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**numbers;
	int		*integers;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	numbers = read_args(argc, argv);
	integers = convert_to_integers(numbers);
	len = int_length(numbers);
	check_for_duplicates(integers, len);
	stack_a = fill_stack_a(integers, len);
	assign_index(stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(integers);
	ft_free_matrix(numbers);
	return (0);
}
