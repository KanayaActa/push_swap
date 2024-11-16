/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:23:41 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/16 10:27:24 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

#define MAX_SIZE 10000

// 操作名の文字列表現
const char *operation_names[] = {
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr",
	"none"
};

typedef struct s_ProgramState
{
	t_Operation	operations[MAX_SIZE * 10];
	int			op_count;
	int			stack_a[MAX_SIZE];
	int			stack_b[MAX_SIZE];
	int			size_a;
	int			size_b;
	int			sorted_unique[MAX_SIZE];
	int			sorted_unique_size;
}	t_ProgramState;

void record_operation(t_ProgramState *state, t_Operation op)
{
	if (state->op_count >= MAX_SIZE * 10) {
		printf("Error: 操作が多すぎます。\n");
		exit(1);
	}
	state->operations[state->op_count++] = op;
}

void sa(t_ProgramState *state)
{
	if (state->size_a >= 2) {
		int temp = state->stack_a[0];
		state->stack_a[0] = state->stack_a[1];
		state->stack_a[1] = temp;
		record_operation(state, OP_SA);
	}
}

void sb(t_ProgramState *state)
{
	if (state->size_b >= 2) {
		int temp = state->stack_b[0];
		state->stack_b[0] = state->stack_b[1];
		state->stack_b[1] = temp;
		record_operation(state, OP_SB);
	}
}

void ss(t_ProgramState *state)
{
	sa(state);
	sb(state);
	if (state->op_count >= 2) {
		state->operations[state->op_count - 2] = OP_SS;
		state->op_count--;
	}
}

void pa(t_ProgramState *state)
{
	if (state->size_b > 0) {
		for (int i = state->size_a; i > 0; i--) {
			state->stack_a[i] = state->stack_a[i - 1];
		}
		state->stack_a[0] = state->stack_b[0];
		state->size_a++;
		for (int i = 0; i < state->size_b - 1; i++) {
			state->stack_b[i] = state->stack_b[i + 1];
		}
		state->size_b--;
		record_operation(state, OP_PA);
	}
}

void pb(t_ProgramState *state)
{
	if (state->size_a > 0) {
		for (int i = state->size_b; i > 0; i--) {
			state->stack_b[i] = state->stack_b[i - 1];
		}
		state->stack_b[0] = state->stack_a[0];
		state->size_b++;
		for (int i = 0; i < state->size_a - 1; i++) {
			state->stack_a[i] = state->stack_a[i + 1];
		}
		state->size_a--;
		record_operation(state, OP_PB);
	}
}

void ra(t_ProgramState *state)
{
	if (state->size_a >= 2) {
		int temp = state->stack_a[0];
		for (int i = 0; i < state->size_a - 1; i++) {
			state->stack_a[i] = state->stack_a[i + 1];
		}
		state->stack_a[state->size_a - 1] = temp;
		record_operation(state, OP_RA);
	}
}

void rb(t_ProgramState *state)
{
	if (state->size_b >= 2) {
		int temp = state->stack_b[0];
		for (int i = 0; i < state->size_b - 1; i++) {
			state->stack_b[i] = state->stack_b[i + 1];
		}
		state->stack_b[state->size_b - 1] = temp;
		record_operation(state, OP_RB);
	}
}

void rr(t_ProgramState *state)
{
	ra(state);
	rb(state);
	if (state->op_count >= 2) {
		state->operations[state->op_count - 2] = OP_RR;
		state->op_count--;
	}
}

void rra(t_ProgramState *state)
{
	if (state->size_a >= 2) {
		int temp = state->stack_a[state->size_a - 1];
		for (int i = state->size_a - 1; i > 0; i--) {
			state->stack_a[i] = state->stack_a[i - 1];
		}
		state->stack_a[0] = temp;
		record_operation(state, OP_RRA);
	}
}

void rrb(t_ProgramState *state)
{
	if (state->size_b >= 2) {
		int temp = state->stack_b[state->size_b - 1];
		for (int i = state->size_b - 1; i > 0; i--) {
			state->stack_b[i] = state->stack_b[i - 1];
		}
		state->stack_b[0] = temp;
		record_operation(state, OP_RRB);
	}
}

void rrr(t_ProgramState *state)
{
	rra(state);
	rrb(state);
	if (state->op_count >= 2) {
		state->operations[state->op_count - 2] = OP_RRR;
		state->op_count--;
	}
}

int compare_int(const void *a, const void *b) {
	return (*(int *)a) - (*(int *)b);
}

void calculate_lis(int *sequence, int size, int *lis, int *lis_size)
{
	int dp[MAX_SIZE];
	int prev_arr[MAX_SIZE];
	int max_dp = 0;
	int index = -1;

	for (int i = 0; i < size; i++) {
		dp[i] = 1;
		prev_arr[i] = -1;
		for (int j = 0; j < i; j++) {
			if (sequence[j] < sequence[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				prev_arr[i] = j;
			}
		}
		if (dp[i] > max_dp) {
			max_dp = dp[i];
			index = i;
		}
	}

	*lis_size = 0;
	while (index != -1) {
		lis[(*lis_size)++] = sequence[index];
		index = prev_arr[index];
	}

	for (int i = 0; i < *lis_size / 2; i++) {
		int temp = lis[i];
		lis[i] = lis[*lis_size - i - 1];
		lis[*lis_size - i - 1] = temp;
	}
}

int is_in_lis(int value, int *lis, int lis_size)
{
	for (int i = 0; i < lis_size; i++) {
		if (lis[i] == value)
			return 1;
	}
	return 0;
}

int find_insert_position(t_ProgramState *state, int b_val)
{
	int position = -1;
	for (int i = 0; i < state->size_a; i++) {
		int a_val = state->stack_a[i];
		int next_a_val = state->stack_a[(i + 1) % state->size_a];
		if ((b_val > a_val && b_val < next_a_val) ||
			(a_val > next_a_val && (b_val > a_val || b_val < next_a_val))) {
			position = (i + 1) % state->size_a;
			break;
		}
	}
	if (position == -1)
		position = 0;
	return position;
}

int calculate_total_cost(t_ProgramState *state, int b_idx, int a_idx)
{
	int len_a = state->size_a;
	int len_b = state->size_b;

	if (b_idx <= len_b / 2 && a_idx <= len_a / 2) {
		return (b_idx > a_idx) ? b_idx : a_idx;
	} else if (b_idx > len_b / 2 && a_idx > len_a / 2) {
		return ((len_b - b_idx) > (len_a - a_idx)) ? (len_b - b_idx) : (len_a - a_idx);
	} else {
		int cost_b = (b_idx <= len_b / 2) ? b_idx : len_b - b_idx;
		int cost_a = (a_idx <= len_a / 2) ? a_idx : len_a - a_idx;
		return cost_b + cost_a;
	}
}

void select_best_move(t_ProgramState *state, int *best_b_idx, int *best_a_idx)
{
	int min_cost = 2147483647;
	*best_b_idx = -1;
	*best_a_idx = -1;
	for (int b_idx = 0; b_idx < state->size_b; b_idx++) {
		int b_val = state->stack_b[b_idx];
		int a_idx = find_insert_position(state, b_val);
		int cost = calculate_total_cost(state, b_idx, a_idx);
		if (cost < min_cost) {
			min_cost = cost;
			*best_b_idx = b_idx;
			*best_a_idx = a_idx;
		}
	}
}

void execute_moves(t_ProgramState *state, int b_idx, int a_idx)
{
	int len_a = state->size_a;
	int len_b = state->size_b;

	if (b_idx <= len_b / 2 && a_idx <= len_a / 2) {
		while (b_idx > 0 && a_idx > 0) {
			rr(state);
			b_idx--;
			a_idx--;
		}
		while (a_idx-- > 0)
			ra(state);
		while (b_idx-- > 0)
			rb(state);
	}
	else if (b_idx > len_b / 2 && a_idx > len_a / 2) {
		while (b_idx < len_b && a_idx < len_a) {
			rrr(state);
			b_idx++;
			a_idx++;
		}
		while (a_idx++ < len_a)
			rra(state);
		while (b_idx++ < len_b)
			rrb(state);
	}
	else {
		if (b_idx <= len_b / 2) {
			while (b_idx-- > 0)
				rb(state);
		} else {
			while (b_idx++ < len_b)
				rrb(state);
		}
		if (a_idx <= len_a / 2) {
			while (a_idx-- > 0)
				ra(state);
		} else {
			while (a_idx++ < len_a)
				rra(state);
		}
	}
	pa(state);
}

void push_b_to_a(t_ProgramState *state) {
	while (state->size_b > 0) {
		int b_idx, a_idx;
		select_best_move(state, &b_idx, &a_idx);
		if (b_idx != -1 && a_idx != -1)
			execute_moves(state, b_idx, a_idx);
	}
}

void final_rotate(t_ProgramState *state) {
	if (state->size_a == 0)
		return;
	int min_val = state->stack_a[0];
	int min_idx = 0;
	for (int i = 1; i < state->size_a; i++) {
		if (state->stack_a[i] < min_val) {
			min_val = state->stack_a[i];
			min_idx = i;
		}
	}
	if (min_idx <= state->size_a / 2) {
		while (min_idx-- > 0)
			ra(state);
	} else {
		min_idx = state->size_a - min_idx;
		while (min_idx-- > 0)
			rra(state);
	}
}

void optimize_operations(t_ProgramState *state) {
	t_Operation optimized_ops[MAX_SIZE * 10];
	int optimized_count = 0;
	int i = 0;
	while (i < state->op_count) {
		if (i < state->op_count - 1) {
			t_Operation op1 = state->operations[i];
			t_Operation op2 = state->operations[i + 1];
			// 取り消し可能な操作のペア
			if ((op1 == OP_RA && op2 == OP_RRA) ||
				(op1 == OP_RRA && op2 == OP_RA) ||
				(op1 == OP_RB && op2 == OP_RRB) ||
				(op1 == OP_RRB && op2 == OP_RB) ||
				(op1 == OP_PA && op2 == OP_PB) ||
				(op1 == OP_PB && op2 == OP_PA) ||
				(op1 == OP_SA && op2 == OP_SA) ||
				(op1 == OP_SB && op2 == OP_SB)) {
				i += 2;
				continue;
			}
			// 同時回転
			if (op1 == OP_RA && op2 == OP_RB) {
				optimized_ops[optimized_count++] = OP_RR;
				i += 2;
				continue;
			}
			if (op1 == OP_RRA && op2 == OP_RRB) {
				optimized_ops[optimized_count++] = OP_RRR;
				i += 2;
				continue;
			}
			if (op1 == OP_SA && op2 == OP_SB) {
				optimized_ops[optimized_count++] = OP_SS;
				i += 2;
				continue;
			}
		}
		optimized_ops[optimized_count++] = state->operations[i];
		i++;
	}
	state->op_count = optimized_count;
	for (int j = 0; j < state->op_count; j++) {
		state->operations[j] = optimized_ops[j];
	}
}

// 列挙型操作を文字列に変換するヘルパー関数
const char* get_operation_name(t_Operation op) {
	if (op >= 0 && op < sizeof(operation_names)/sizeof(operation_names[0])) {
		return operation_names[op];
	}
	return "unknown";
}

void move_non_lis_to_b(t_ProgramState *state, int *lis, int lis_size, int mid_value) {
	int count = 0;
	int total_elements = state->size_a;
	while (count < total_elements) {
		if (is_in_lis(state->stack_a[0], lis, lis_size)) {
			ra(state);
		} else {
			pb(state);
			if (state->size_b > 1 && state->stack_b[0] < mid_value) {
				rb(state);
			}
		}
		count++;
	}
}

void sort_stack(t_ProgramState *state) {
	int lis[MAX_SIZE];
	int lis_size = 0;
	calculate_lis(state->stack_a, state->size_a, lis, &lis_size);

	int mid_value = state->sorted_unique[state->sorted_unique_size / 2];

	move_non_lis_to_b(state, lis, lis_size, mid_value);

	push_b_to_a(state);

	final_rotate(state);
}

int push_swap(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Error: 数字のリストを引数として指定してください。\n");
		return 1;
	}

	t_ProgramState state;
	state.op_count = 0;
	state.size_a = 0;
	state.size_b = 0;
	state.sorted_unique_size = 0;
	memset(state.operations, 0, sizeof(state.operations));
	memset(state.stack_a, 0, sizeof(state.stack_a));
	memset(state.stack_b, 0, sizeof(state.stack_b));
	memset(state.sorted_unique, 0, sizeof(state.sorted_unique));

	for (int i = 1; i < argc; i++) {
		char *endptr;
		int num = strtol(argv[i], &endptr, 10);
		if (*endptr != '\0') {
			printf("Error: すべての引数は整数でなければなりません。\n");
			return 1;
		}
		state.stack_a[state.size_a++] = num;
	}

	// 重複チェック
	for (int i = 0; i < state.size_a; i++) {
		for (int j = i + 1; j < state.size_a; j++) {
			if (state.stack_a[i] == state.stack_a[j]) {
				printf("Error: 重複した数値が含まれています。\n");
				return 1;
			}
		}
	}

	// ソートしてユニークな値を取得
	memcpy(state.sorted_unique, state.stack_a, state.size_a * sizeof(int));
	state.sorted_unique_size = state.size_a;
	qsort(state.sorted_unique, state.sorted_unique_size, sizeof(int), compare_int);

	// 各値をインデックスに置き換え
	for (int i = 0; i < state.size_a; i++) {
		for (int j = 0; j < state.sorted_unique_size; j++) {
			if (state.stack_a[i] == state.sorted_unique[j]) {
				state.stack_a[i] = j;
				break;
			}
		}
	}

	sort_stack(&state);

	optimize_operations(&state);

	for (int i = 0; i < state.op_count; i++) {
		printf("%s\n", get_operation_name(state.operations[i]));
	}

	return (0);
}
