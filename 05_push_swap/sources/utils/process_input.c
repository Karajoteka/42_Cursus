/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:42:58 by aorcha-m          #+#    #+#             */
/*   Updated: 2024/03/27 19:40:47 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*convert_to_integers(char **numbers)
{
	int	*integers;
	int	i;
	int	len;

	len = int_length(numbers);
	integers = (int *)malloc(sizeof(int) * len);
	if (!integers)
		error_and_exit();
	i = 0;
	while (i < len)
	{
		if (!is_in_range(numbers[i]))
		{
			free(integers);
			error_and_exit();
		}
		integers[i] = ft_atoi(numbers[i]);
		i++;
	}
	return (integers);
}

char	**split_and_validate_numbers(char *all_args)
{
	char	**numbers;
	int		i;

	numbers = ft_split(all_args, ' ');
	free(all_args);
	if (!numbers)
		error_and_exit();
	i = 0;
	while (numbers[i])
	{
		if (!is_number(numbers[i]))
			error_and_exit();
		i++;
	}
	return (numbers);
}

char	*join_split_args(char *all_args, char **split_arg)
{
	char	*temp;
	int		j;

	j = 0;
	while (split_arg[j])
	{
		temp = ft_strjoin(all_args, " ");
		free(all_args);
		all_args = temp;
		temp = ft_strjoin(all_args, split_arg[j]);
		free(all_args);
		all_args = temp;
		j++;
	}
	return (all_args);
}

char	*process_args(int argc, char **argv)
{
	char	*all_args;
	char	**split_arg;
	int		i;

	if (argc <= 1)
		return (NULL);
	i = 1;
	all_args = ft_strdup(argv[i]);
	i++;
	while (i < argc)
	{
		split_arg = ft_split(argv[i], ' ');
		all_args = join_split_args(all_args, split_arg);
		ft_free_matrix(split_arg);
		i++;
	}
	return (all_args);
}

char	**read_args(int argc, char **argv)
{
	char	**numbers;
	char	*all_args;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (argv[1][0] == '\0' && argc == 2)
			error_and_exit();
		if ((ft_strcmp(argv[i], "-") == 0 || ft_strcmp(argv[i], "+") == 0)
			&& !ft_isdigit(argv[i][1]))
			error_and_exit();
		i++;
	}
	all_args = process_args(argc, argv);
	if (!all_args)
		return (NULL);
	numbers = split_and_validate_numbers(all_args);
	return (numbers);
}
