/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:42:22 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/19 02:06:02 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_two(t_ProgramState *state)
{
	if (state->stack_a[0] > state->stack_a[1])
		sa(state);
}

void	sort_three(t_ProgramState *state)
{
	const int	a = state->stack_a[0];
	const int	b = state->stack_a[1];
	const int	c = state->stack_a[2];

	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa(state);
		ra(state);
	}
	else if (b < a && a < c)
		sa(state);
	else if (a < b && a > c)
		rra(state);
	else if (c < b && b < a)
	{
		sa(state);
		rra(state);
	}
	else if (b < c && c < a)
		ra(state);
}

void	sort_four(t_ProgramState *state)
{
	int	min_idx;

	min_idx = find_min_index(state->stack_a, state->size_a);
	if (min_idx == 1)
		ra(state);
	else if (min_idx == 2)
	{
		ra(state);
		ra(state);
	}
	else if (min_idx == 3)
		rra(state);
	pb(state);
	sort_three(state);
	pa(state);
}

void	sort_five(t_ProgramState *state)
{
	int	min_idx;

	min_idx = find_min_index(state->stack_a, state->size_a);
	if (min_idx == 1)
		ra(state);
	else if (min_idx == 2)
	{
		ra(state);
		ra(state);
	}
	else if (min_idx == 3)
	{
		rra(state);
		rra(state);
	}
	else if (min_idx == 4)
		rra(state);
	pb(state);
	sort_four(state);
	pa(state);
}
