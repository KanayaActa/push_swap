/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_check_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:40:08 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 22:40:09 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

int	parse_arguments(t_ProgramState *state, int argc, char *argv[])
{
	int		i;
	long	num;
	char	*endptr;

	i = 1;
	while (i < argc)
	{
		num = ft_strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || num < INT_MIN || num > INT_MAX)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		state->stack_a[state->size_a] = (int)num;
		state->size_a++;
		i++;
	}
	return (0);
}

int	check_duplicates(t_ProgramState *state)
{
	int	i;
	int	j;

	i = 0;
	while (i < state->size_a)
	{
		j = i + 1;
		while (j < state->size_a)
		{
			if (state->stack_a[i] == state->stack_a[j])
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
