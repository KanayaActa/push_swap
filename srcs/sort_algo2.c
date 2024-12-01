/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:42:29 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 22:42:30 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	execute_moves_both_down(t_ProgramState *state, int *b_idx, int *a_idx)
{
	int	len_a;
	int	len_b;

	len_a = state->size_a;
	len_b = state->size_b;
	while (*b_idx < len_b && *a_idx < len_a)
	{
		rrr(state);
		(*b_idx)++;
		(*a_idx)++;
	}
	while (*a_idx < len_a)
	{
		rra(state);
		(*a_idx)++;
	}
	while (*b_idx < len_b)
	{
		rrb(state);
		(*b_idx)++;
	}
}

void	execute_moves_b_stack(t_ProgramState *state, int b_idx)
{
	int	len_b;

	len_b = state->size_b;
	if (b_idx <= len_b / 2)
	{
		while (b_idx > 0)
		{
			rb(state);
			b_idx--;
		}
	}
	else
	{
		while (b_idx < len_b)
		{
			rrb(state);
			b_idx++;
		}
	}
}

void	execute_moves_a_stack(t_ProgramState *state, int a_idx)
{
	int	len_a;

	len_a = state->size_a;
	if (a_idx <= len_a / 2)
	{
		while (a_idx > 0)
		{
			ra(state);
			a_idx--;
		}
	}
	else
	{
		while (a_idx < len_a)
		{
			rra(state);
			a_idx++;
		}
	}
}

void	execute_moves_separate(t_ProgramState *state, int b_idx, int a_idx)
{
	execute_moves_b_stack(state, b_idx);
	execute_moves_a_stack(state, a_idx);
}

void	execute_moves(t_ProgramState *state, int b_idx, int a_idx)
{
	int	len_a;
	int	len_b;

	len_a = state->size_a;
	len_b = state->size_b;
	if (b_idx <= len_b / 2 && a_idx <= len_a / 2)
		execute_moves_both_up(state, &b_idx, &a_idx);
	else if (b_idx > len_b / 2 && a_idx > len_a / 2)
		execute_moves_both_down(state, &b_idx, &a_idx);
	else
		execute_moves_separate(state, b_idx, a_idx);
	pa(state);
}
