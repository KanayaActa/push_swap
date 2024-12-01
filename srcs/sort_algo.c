/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:42:27 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 22:42:28 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "limits.h"

int	find_insert_position(t_ProgramState *state, int b_val)
{
	int	position;
	int	i;
	int	a_val;
	int	next_a_val;

	position = -1;
	i = 0;
	while (i < state->size_a)
	{
		a_val = state->stack_a[i];
		next_a_val = state->stack_a[(i + 1) % state->size_a];
		if ((b_val > a_val && b_val < next_a_val) \
		|| (a_val > next_a_val && (b_val > a_val || b_val < next_a_val)))
		{
			position = (i + 1) % state->size_a;
			break ;
		}
		i++;
	}
	if (position == -1)
		position = 0;
	return (position);
}

int	calculate_rotation_cost(int idx, int len)
{
	if (idx <= len / 2)
		return (idx);
	else
		return (len - idx);
}

int	calculate_total_cost(t_ProgramState *state, int b_idx, int a_idx)
{
	int	len_a;
	int	len_b;
	int	cost_b;
	int	cost_a;

	len_a = state->size_a;
	len_b = state->size_b;
	cost_b = calculate_rotation_cost(b_idx, len_b);
	cost_a = calculate_rotation_cost(a_idx, len_a);
	if ((b_idx <= len_b / 2 && a_idx <= len_a / 2) \
	|| (b_idx > len_b / 2 && a_idx > len_a / 2))
	{
		if (cost_b > cost_a)
			return (cost_b);
		else
			return (cost_a);
	}
	else
		return (cost_b + cost_a);
}

void	select_best_move(t_ProgramState *state, \
						int *best_b_idx, int *best_a_idx)
{
	int	min_cost;
	int	b_idx;
	int	b_val;
	int	a_idx;
	int	cost;

	min_cost = INT_MAX;
	*best_b_idx = -1;
	*best_a_idx = -1;
	b_idx = 0;
	while (b_idx < state->size_b)
	{
		b_val = state->stack_b[b_idx];
		a_idx = find_insert_position(state, b_val);
		cost = calculate_total_cost(state, b_idx, a_idx);
		if (cost < min_cost)
		{
			min_cost = cost;
			*best_b_idx = b_idx;
			*best_a_idx = a_idx;
		}
		b_idx++;
	}
}

void	execute_moves_both_up(t_ProgramState *state, int *b_idx, int *a_idx)
{
	while (*b_idx > 0 && *a_idx > 0)
	{
		rr(state);
		(*b_idx)--;
		(*a_idx)--;
	}
	while (*a_idx > 0)
	{
		ra(state);
		(*a_idx)--;
	}
	while (*b_idx > 0)
	{
		rb(state);
		(*b_idx)--;
	}
}
