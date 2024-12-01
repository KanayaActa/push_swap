/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:39:50 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 22:39:51 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	pa(t_ProgramState *state)
{
	int	i;

	if (state->size_b > 0)
	{
		i = state->size_a;
		while (i > 0)
		{
			state->stack_a[i] = state->stack_a[i - 1];
			i--;
		}
		state->stack_a[0] = state->stack_b[0];
		state->size_a++;
		i = 0;
		while (i < state->size_b - 1)
		{
			state->stack_b[i] = state->stack_b[i + 1];
			i++;
		}
		state->size_b--;
		record_operation(state, OP_PA);
	}
}

void	pb(t_ProgramState *state)
{
	int	i;

	if (state->size_a > 0)
	{
		i = state->size_b;
		while (i > 0)
		{
			state->stack_b[i] = state->stack_b[i - 1];
			i--;
		}
		state->stack_b[0] = state->stack_a[0];
		state->size_b++;
		i = 0;
		while (i < state->size_a - 1)
		{
			state->stack_a[i] = state->stack_a[i + 1];
			i++;
		}
		state->size_a--;
		record_operation(state, OP_PB);
	}
}
