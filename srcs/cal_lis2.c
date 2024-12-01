/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_lis2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:39:40 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/19 01:02:12 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	reverse_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap(&array[i], &array[size - i - 1]);
		i++;
	}
}

void	calculate_lis(int *sequence, int size, int *lis, int *lis_size)
{
	int	dp[MAX_SIZE];
	int	prev_arr[MAX_SIZE];
	int	max_dp;
	int	index;

	fill_dp_arrays(sequence, size, dp, prev_arr);
	find_max_dp(dp, size, &max_dp, &index);
	*lis_size = reconstruct_lis(sequence, prev_arr, index, lis);
	reverse_array(lis, *lis_size);
}

int	is_in_lis(int value, int *lis, int lis_size)
{
	int	i;

	i = 0;
	while (i < lis_size)
	{
		if (lis[i] == value)
			return (1);
		i++;
	}
	return (0);
}
