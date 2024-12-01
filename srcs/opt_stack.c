/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:40:02 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 22:40:03 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_inverse_operations(t_Operation op1, t_Operation op2)
{
	if ((op1 == OP_RA && op2 == OP_RRA) \
	|| (op1 == OP_RRA && op2 == OP_RA) \
	|| (op1 == OP_RB && op2 == OP_RRB) \
	|| (op1 == OP_RRB && op2 == OP_RB) \
	|| (op1 == OP_PA && op2 == OP_PB) \
	|| (op1 == OP_PB && op2 == OP_PA) \
	|| (op1 == OP_SA && op2 == OP_SA) \
	|| (op1 == OP_SB && op2 == OP_SB))
		return (1);
	else
		return (0);
}

int	can_combine_operations(t_Operation op1, t_Operation op2, \
							t_Operation *combined_op)
{
	if (op1 == OP_RA && op2 == OP_RB)
	{
		*combined_op = OP_RR;
		return (1);
	}
	if (op1 == OP_RRA && op2 == OP_RRB)
	{
		*combined_op = OP_RRR;
		return (1);
	}
	if (op1 == OP_SA && op2 == OP_SB)
	{
		*combined_op = OP_SS;
		return (1);
	}
	return (0);
}

void	handle_inverse_operations(int *i)
{
	*i += 2;
}

void	comb_op(t_Operation *optimized_ops, int *optimized_count, \
								t_Operation combined_op, int *i)
{
	optimized_ops[*optimized_count] = combined_op;
	(*optimized_count)++;
	*i += 2;
}
