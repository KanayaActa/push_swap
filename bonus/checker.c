/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:06:28 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/26 21:25:33 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "push_swap.h"

#define MAX_SIZE 10000

void	execute_operation(t_ProgramState *state, const char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		sa(state);
	else if (ft_strcmp(op, "sb") == 0)
		sb(state);
	else if (ft_strcmp(op, "ss") == 0)
		ss(state);
	else if (ft_strcmp(op, "pa") == 0)
		pa(state);
	else if (ft_strcmp(op, "pb") == 0)
		pb(state);
	else if (ft_strcmp(op, "ra") == 0)
		ra(state);
	else if (ft_strcmp(op, "rb") == 0)
		rb(state);
	else if (ft_strcmp(op, "rr") == 0)
		rr(state);
	else if (ft_strcmp(op, "rra") == 0)
		rra(state);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(state);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(state);
	else
		exit((write(2, "Error\n", 6), 1));
}

int	checker(int argc, char *argv[])
{
	t_ProgramState	state;
	char			*op_line;
	size_t			len;

	if (argc < 2)
		return (0);
	initialize_state(&state);
	if (parse_arguments(&state, argc, argv) || check_duplicates(&state))
		return (1);
	while (1)
	{
		op_line = get_next_line(0);
		if (!op_line)
			break ;
		len = ft_strlen(op_line);
		if (len > 0 && op_line[len - 1] == '\n')
			op_line[len - 1] = '\0';
		execute_operation(&state, op_line);
		free(op_line);
	}
	if (is_sorted(&state) && state.size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
