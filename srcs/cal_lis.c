/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:44:12 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/17 21:45:19 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	fill_dp_arrays(int *sequence, int size, int *dp, int *prev_arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		dp[i] = 1;
		prev_arr[i] = -1;
		j = 0;
		while (j < i)
		{
			if (sequence[j] < sequence[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev_arr[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	find_max_dp(int *dp, int size, int *max_dp, int *index)
{
	int	i;

	*max_dp = 0;
	*index = -1;
	i = 0;
	while (i < size)
	{
		if (dp[i] > *max_dp)
		{
			*max_dp = dp[i];
			*index = i;
		}
		i++;
	}
}

int	reconstruct_lis(int *sequence, int *prev_arr, int index, int *lis)
{
	int	lis_size;

	lis_size = 0;
	while (index != -1)
	{
		lis[lis_size] = sequence[index];
		lis_size++;
		index = prev_arr[index];
	}
	return (lis_size);
}
