/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:12:01 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/27 19:41:19 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// operations

void				swap(t_stack **head);
void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b);

void				push(t_stack **src, t_stack **dest);
void				do_pa(t_stack **stack_a, t_stack **stack_b);
void				do_pb(t_stack **stack_a, t_stack **stack_b);

void				rotate(t_stack **stack);
void				do_ra(t_stack **stack_a);
void				do_rb(t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b);

void				reverse_rotate(t_stack **stack);
void				do_rra(t_stack **stack_a);
void				do_rrb(t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);

// sorting

void				rotate_to_right_position(t_stack **stack_a);
void				execute_actions_b(t_stack **stack_b,
						t_stack *min_cost_element);
void				execute_actions_a(t_stack **stack_a,
						t_stack *min_cost_element);
void				execute_actions(t_stack **stack_a, t_stack **stack_b,
						t_stack *min_cost_element);
int					ft_abs(int n);
t_stack				*get_low_cost(t_stack *stack_b);
void				calculate_costs(t_stack **stack_a, t_stack **stack_b);
int					calculate_cost(int position, int len);
void				find_three_largest_index(t_stack **stack,
						int *largest_indices);
void				find_two_smallest_index(t_stack **stack,
						int *smallest_indices);
void				assign_target_pos(t_stack **stack_a, t_stack **stack_b);
void				assign_positions(t_stack **stack, t_stack **stack_b);
void				move_elements_to_b(t_stack **stack_a, t_stack **stack_b);
void				move_elements_to_b_first_half(t_stack **stack_a,
						t_stack **stack_b, int largest_index[3], int mid_index);
void				move_elements_to_b_second_half(t_stack **stack_a,
						t_stack **stack_b, int largest_index[3], int mid_index);
void				sort_stack_over_five(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack_a);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack *head);

// create and fill stack

void				print_stack(t_stack *head, char stack_name,
						t_stack *min_cost_element);
t_stack				*fill_stack_a(int *integers, int len);
t_stack				*create_node(int value);
int					stack_length(t_stack *head);
void				assign_index(t_stack *head);
void				free_stack(t_stack *head);

// read and process input

char				**read_args(int argc, char **argv);
char				*process_args(int argc, char **argv);
char				*join_split_args(char *all_args, char **split_arg);
char				**split_and_validate_numbers(char *all_args);
int					is_number(char *str);
int					is_in_range(char *str);
int					int_length(char **numbers);
int					*convert_to_integers(char **numbers);
int					check_for_duplicates(int *integers, int len);
void				error_and_exit(void);

#endif