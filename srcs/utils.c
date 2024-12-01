/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:42:35 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/19 00:56:24 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_cmp(const void *a, const void *b)
{
	const int	int_a = *(const int *)a;
	const int	int_b = *(const int *)b;

	if (int_a < int_b)
		return (-1);
	else if (int_a > int_b)
		return (1);
	else
		return (0);
}

void	initialize_state(t_ProgramState *state)
{
	state->op_count = 0;
	state->size_a = 0;
	state->size_b = 0;
	state->sorted_unique_size = 0;
	ft_memset(state->operations, 0, sizeof(state->operations));
	ft_memset(state->stack_a, 0, sizeof(state->stack_a));
	ft_memset(state->stack_b, 0, sizeof(state->stack_b));
	ft_memset(state->sorted_unique, 0, sizeof(state->sorted_unique));
}

int	is_sorted(t_ProgramState *state)
{
	int	i;

	i = 0;
	while (i < state->size_a - 1)
	{
		if (state->stack_a[i] > state->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

const char	*get_operation_name(t_Operation op)
{
	const char	*operation_names[] = {
		"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr", "none"
	};

	if (op >= 0 && op < \
	(int)(sizeof(operation_names) / sizeof(operation_names[0])))
		return (operation_names[op]);
	return ("unknown");
}

void	print_operations(t_ProgramState *state)
{
	int	i;

	i = 0;
	while (i < state->op_count)
	{
		ft_printf("%s\n", get_operation_name(state->operations[i]));
		i++;
	}
}
