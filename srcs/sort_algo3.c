/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:42:32 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 22:42:33 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_b_to_a(t_ProgramState *state)
{
	int	b_idx;
	int	a_idx;

	while (state->size_b > 0)
	{
		select_best_move(state, &b_idx, &a_idx);
		if (b_idx != -1 && a_idx != -1)
			execute_moves(state, b_idx, a_idx);
	}
}

int	find_min_index(int *stack, int size)
{
	int	i;
	int	min_idx;
	int	min_val;

	min_idx = 0;
	min_val = stack[0];
	i = 1;
	while (i < size)
	{
		if (stack[i] < min_val)
		{
			min_val = stack[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

void	rotate_to_min_index(t_ProgramState *state, int min_idx)
{
	int	len_a;

	len_a = state->size_a;
	if (min_idx <= len_a / 2)
	{
		while (min_idx > 0)
		{
			ra(state);
			min_idx--;
		}
	}
	else
	{
		min_idx = len_a - min_idx;
		while (min_idx > 0)
		{
			rra(state);
			min_idx--;
		}
	}
}

void	final_rotate(t_ProgramState *state)
{
	int	min_idx;

	if (state->size_a == 0)
		return ;
	min_idx = find_min_index(state->stack_a, state->size_a);
	rotate_to_min_index(state, min_idx);
}

void	move_non_lis_to_b(t_ProgramState *state, int *lis, int lis_size,
						int mid_value)
{
	int	count;
	int	total_elements;

	count = 0;
	total_elements = state->size_a;
	while (count < total_elements)
	{
		if (is_in_lis(state->stack_a[0], lis, lis_size))
			ra(state);
		else
		{
			pb(state);
			if (state->size_b > 1 && state->stack_b[0] < mid_value)
				rb(state);
		}
		count++;
	}
}
