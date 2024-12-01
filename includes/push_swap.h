/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:32:09 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/19 02:06:11 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

# define MAX_SIZE 10000

typedef enum e_Operations{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_NONE
}	t_Operation;

typedef struct s_ProgramState
{
	t_Operation		operations[MAX_SIZE * 10];
	int				op_count;
	int				stack_a[MAX_SIZE];
	int				stack_b[MAX_SIZE];
	int				size_a;
	int				size_b;
	int				sorted_unique[MAX_SIZE];
	int				sorted_unique_size;
}	t_ProgramState;

int				push_swap(int argc, char **argv);
int				checker(int argc, char *argv[]);

// == basic operation ==

void			record_operation(t_ProgramState *state, t_Operation op);

// --swap--
void			sa(t_ProgramState *state);
void			sb(t_ProgramState *state);
void			ss(t_ProgramState *state);

// --push--
void			pa(t_ProgramState *state);
void			pb(t_ProgramState *state);

// --rev--
void			ra(t_ProgramState *state);
void			rb(t_ProgramState *state);
void			rr(t_ProgramState *state);

// --revrev--
void			rra(t_ProgramState *state);
void			rrb(t_ProgramState *state);
void			rrr(t_ProgramState *state);

// == utils ==
int				ft_cmp(const void *a, const void *b);
void			initialize_state(t_ProgramState *state);
int				is_sorted(t_ProgramState *state);
const char		*get_operation_name(t_Operation op);
void			print_operations(t_ProgramState *state);

// == parse_and_check_args ==
int				parse_arguments(t_ProgramState *state, int argc, char *argv[]);
int				check_duplicates(t_ProgramState *state);

// == cal_lis ==
void			fill_dp_arrays(int *sequence, int size, int *dp, int *prev_arr);
void			find_max_dp(int *dp, int size, int *max_dp, int *index);
int				reconstruct_lis(int *sequence, int *prev_arr, \
								int index, int *lis);
void			reverse_array(int *array, int size);
void			calculate_lis(int *sequence, int size, int *lis, int *lis_size);
int				is_in_lis(int value, int *lis, int lis_size);

// == opt_stack ==
int				is_inverse_operations(t_Operation op1, t_Operation op2);
int				can_combine_operations(t_Operation op1, t_Operation op2, \
							t_Operation *combined_op);
void			handle_inverse_operations(int *i);
void			comb_op(t_Operation *optimized_ops, int *optimized_count, \
								t_Operation combined_op, int *i);
void			handle_single_operation(t_ProgramState *state, \
							t_Operation *optimized_ops, \
							int *optimized_count, int *i);
void			process_operations(t_ProgramState *state, \
						t_Operation *optimized_ops, \
						int *optimized_count);
void			copy_optimized_operations(t_ProgramState *state, \
								t_Operation *optimized_ops, \
								int optimized_count);
void			optimize_operations(t_ProgramState *state);

// == sort_algo ==
int				find_insert_position(t_ProgramState *state, int b_val);
int				calculate_rotation_cost(int idx, int len);
int				calculate_total_cost(t_ProgramState *state, \
							int b_idx, int a_idx);
void			select_best_move(t_ProgramState *state, \
						int *best_b_idx, int *best_a_idx);
void			execute_moves_both_up(t_ProgramState *state, int *b_idx, \
									int *a_idx);
void			execute_moves_both_down(t_ProgramState *state, int *b_idx, \
									int *a_idx);
void			execute_moves_b_stack(t_ProgramState *state, int b_idx);
void			execute_moves_a_stack(t_ProgramState *state, int a_idx);
void			execute_moves_separate(t_ProgramState *state, \
							int b_idx, int a_idx);
void			execute_moves(t_ProgramState *state, int b_idx, int a_idx);
void			push_b_to_a(t_ProgramState *state);
int				find_min_index(int *stack, int size);
void			rotate_to_min_index(t_ProgramState *state, int min_idx);
void			final_rotate(t_ProgramState *state);
void			move_non_lis_to_b(t_ProgramState *state, \
						int *lis, int lis_size, \
						int mid_value);

// == short_stack ==
void			sort_two(t_ProgramState *state);
void			execute_sort_three_case(t_ProgramState *state, int case_num);
void			sort_three(t_ProgramState *state);
void			sort_four(t_ProgramState *state);
void			sort_five(t_ProgramState *state);

#endif