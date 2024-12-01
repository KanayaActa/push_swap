/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:47:57 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 22:40:00 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sa(t_ProgramState *state)
{
	int	temp;

	if (state->size_a >= 2)
	{
		temp = state->stack_a[0];
		state->stack_a[0] = state->stack_a[1];
		state->stack_a[1] = temp;
		record_operation(state, OP_SA);
	}
}

void	sb(t_ProgramState *state)
{
	int	temp;

	if (state->size_b >= 2)
	{
		temp = state->stack_b[0];
		state->stack_b[0] = state->stack_b[1];
		state->stack_b[1] = temp;
		record_operation(state, OP_SB);
	}
}

void	ss(t_ProgramState *state)
{
	sa(state);
	sb(state);
	if (state->op_count >= 2)
	{
		state->operations[state->op_count - 2] = OP_SS;
		state->op_count--;
	}
}
