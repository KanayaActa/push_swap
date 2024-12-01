/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_stack2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:40:05 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 22:40:07 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	handle_single_operation(t_ProgramState *state, \
							t_Operation *optimized_ops, \
							int *optimized_count, int *i)
{
	optimized_ops[*optimized_count] = state->operations[*i];
	(*optimized_count)++;
	(*i)++;
}

void	process_operations(t_ProgramState *state, t_Operation *optimized_ops, \
						int *optimized_count)
{
	int			i;
	t_Operation	op1;
	t_Operation	op2;
	t_Operation	combined_op;

	i = 0;
	while (i < state->op_count)
	{
		if (i < state->op_count - 1)
		{
			op1 = state->operations[i];
			op2 = state->operations[i + 1];
			if (is_inverse_operations(op1, op2))
			{
				handle_inverse_operations(&i);
				continue ;
			}
			if (can_combine_operations(op1, op2, &combined_op))
			{
				comb_op(optimized_ops, optimized_count, combined_op, &i);
				continue ;
			}
		}
		handle_single_operation(state, optimized_ops, optimized_count, &i);
	}
}

void	copy_optimized_operations(t_ProgramState *state, \
								t_Operation *optimized_ops, \
								int optimized_count)
{
	int	i;

	state->op_count = optimized_count;
	i = 0;
	while (i < state->op_count)
	{
		state->operations[i] = optimized_ops[i];
		i++;
	}
}

void	optimize_operations(t_ProgramState *state)
{
	t_Operation	optimized_ops[MAX_SIZE * 10];
	int			optimized_count;

	optimized_count = 0;
	process_operations(state, optimized_ops, &optimized_count);
	copy_optimized_operations(state, optimized_ops, optimized_count);
}
