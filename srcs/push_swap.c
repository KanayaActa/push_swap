/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:40:40 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/18 22:58:04 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "libft.h"
#include "push_swap.h"

void	record_operation(t_ProgramState *state, t_Operation op)
{
	if (state->op_count >= MAX_SIZE * 10)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	state->operations[state->op_count] = op;
	state->op_count++;
}

void	compress_args(t_ProgramState *state)
{
	int	i;
	int	j;

	ft_memcpy(state->sorted_unique, state->stack_a,
		state->size_a * sizeof(int));
	state->sorted_unique_size = state->size_a;
	ft_qsort(state->sorted_unique, state->sorted_unique_size,
		sizeof(int), ft_cmp);
	i = 0;
	while (i < state->size_a)
	{
		j = 0;
		while (j < state->sorted_unique_size)
		{
			if (state->stack_a[i] == state->sorted_unique[j])
			{
				state->stack_a[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	sort_stack(t_ProgramState *state)
{
	int	lis[MAX_SIZE];
	int	lis_size;
	int	mid_value;
	int	*compressed_values;

	lis_size = 0;
	calculate_lis(state->stack_a, state->size_a, lis, &lis_size);
	compressed_values = __builtin_alloca(state->size_a * sizeof(int));
	ft_memcpy(compressed_values, state->stack_a, state->size_a * sizeof(int));
	ft_qsort(compressed_values, state->size_a, sizeof(int), ft_cmp);
	mid_value = compressed_values[state->size_a / 2];
	move_non_lis_to_b(state, lis, lis_size, mid_value);
	push_b_to_a(state);
	final_rotate(state);
}

void	push_swap_u5(t_ProgramState *state)
{
	if (state->size_a == 2)
		sort_two(state);
	else if (state->size_a == 3)
		sort_three(state);
	else if (state->size_a == 4)
		sort_four(state);
	else if (state->size_a == 5)
		sort_five(state);
}

int	push_swap(int argc, char *argv[])
{
	t_ProgramState	state;

	if (argc < 2)
		return (0);
	initialize_state(&state);
	if (parse_arguments(&state, argc, argv))
		return (1);
	if (check_duplicates(&state))
		return (1);
	compress_args(&state);
	if (is_sorted(&state))
		return (0);
	if (state.size_a <= 5)
		push_swap_u5(&state);
	else
		sort_stack(&state);
	optimize_operations(&state);
	print_operations(&state);
	return (0);
}
