/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:39:55 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 22:43:50 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rra(t_ProgramState *state)
{
	int	temp;
	int	i;

	if (state->size_a >= 2)
	{
		temp = state->stack_a[state->size_a - 1];
		i = state->size_a - 1;
		while (i > 0)
		{
			state->stack_a[i] = state->stack_a[i - 1];
			i--;
		}
		state->stack_a[0] = temp;
		record_operation(state, OP_RRA);
	}
}

void	rrb(t_ProgramState *state)
{
	int	temp;
	int	i;

	if (state->size_b >= 2)
	{
		temp = state->stack_b[state->size_b - 1];
		i = state->size_b - 1;
		while (i > 0)
		{
			state->stack_b[i] = state->stack_b[i - 1];
			i--;
		}
		state->stack_b[0] = temp;
		record_operation(state, OP_RRB);
	}
}

void	rrr(t_ProgramState *state)
{
	rra(state);
	rrb(state);
	if (state->op_count >= 2)
	{
		state->operations[state->op_count - 2] = OP_RRR;
		state->op_count--;
	}
}
