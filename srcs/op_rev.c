/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:39:52 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 22:43:47 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ra(t_ProgramState *state)
{
	int	temp;
	int	i;

	if (state->size_a >= 2)
	{
		temp = state->stack_a[0];
		i = 0;
		while (i < state->size_a - 1)
		{
			state->stack_a[i] = state->stack_a[i + 1];
			i++;
		}
		state->stack_a[state->size_a - 1] = temp;
		record_operation(state, OP_RA);
	}
}

void	rb(t_ProgramState *state)
{
	int	temp;
	int	i;

	if (state->size_b >= 2)
	{
		temp = state->stack_b[0];
		i = 0;
		while (i < state->size_b - 1)
		{
			state->stack_b[i] = state->stack_b[i + 1];
			i++;
		}
		state->stack_b[state->size_b - 1] = temp;
		record_operation(state, OP_RB);
	}
}

void	rr(t_ProgramState *state)
{
	ra(state);
	rb(state);
	if (state->op_count >= 2)
	{
		state->operations[state->op_count - 2] = OP_RR;
		state->op_count--;
	}
}
