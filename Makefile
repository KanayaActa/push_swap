# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 08:24:02 by miwasa            #+#    #+#              #
#    Updated: 2024/11/19 00:59:07 by miwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = push_swap
CHECKER         = checker

DIR             = .
FT_DIR          = $(DIR)/libft
LIBFT           = $(FT_DIR)/libft.a
INCS_DIR        = $(DIR)/includes
SRCS_DIR        = $(DIR)/srcs
CHECKER_DIR     = $(DIR)/bonus
OBJS_DIR        = $(DIR)/objs

CC              = cc
CFLAGS          = -Wall -Wextra -Werror
IDFLAGS         = -I$(INCS_DIR) -I$(FT_DIR)

COMMON_SRCS = \
    op_swap.c \
    op_push.c \
    op_rev.c \
    op_revrev.c \
    utils.c \
    push_swap.c \
    parse_and_check_args.c \
    cal_lis.c \
    cal_lis2.c \
    opt_stack.c \
    opt_stack2.c \
    sort_algo.c \
    sort_algo2.c \
    sort_algo3.c \
    short_stack.c

PUSH_SWAP_SRCS = \
    main.c \

CHECKER_SRCS = \
    checker.c \
	main.c

COMMON_SRCS := $(addprefix $(SRCS_DIR)/, $(COMMON_SRCS))
PUSH_SWAP_SRCS := $(addprefix $(SRCS_DIR)/, $(PUSH_SWAP_SRCS))
CHECKER_SRCS := $(addprefix $(CHECKER_DIR)/, $(CHECKER_SRCS))

PUSH_SWAP_COMMON_OBJS := $(addprefix $(OBJS_DIR)/push_swap/common/, $(notdir $(COMMON_SRCS:.c=.o)))
CHECKER_COMMON_OBJS := $(addprefix $(OBJS_DIR)/checker/common/, $(notdir $(COMMON_SRCS:.c=.o)))
PUSH_SWAP_OBJS := $(addprefix $(OBJS_DIR)/push_swap/, $(notdir $(PUSH_SWAP_SRCS:.c=.o)))
CHECKER_OBJS := $(addprefix $(OBJS_DIR)/checker/, $(notdir $(CHECKER_SRCS:.c=.o)))

.PHONY: all clean fclean re test norm bonus

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(FT_DIR)

$(NAME): $(PUSH_SWAP_OBJS) $(PUSH_SWAP_COMMON_OBJS) $(LIBFT)
	$(CC) $(CFLAGS_PUSH_SWAP) $(IDFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) $(PUSH_SWAP_COMMON_OBJS) $(LIBFT)

$(CHECKER): $(CHECKER_OBJS) $(CHECKER_COMMON_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(IDFLAGS) -o $(CHECKER) $(CHECKER_OBJS) $(CHECKER_COMMON_OBJS) $(LIBFT)

$(OBJS_DIR)/push_swap/common/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS_PUSH_SWAP) $(IDFLAGS) -c $< -o $@

$(OBJS_DIR)/checker/common/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IDFLAGS) -c $< -o $@

$(OBJS_DIR)/push_swap/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS_PUSH_SWAP) $(IDFLAGS) -c $< -o $@

$(OBJS_DIR)/checker/%.o: $(CHECKER_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IDFLAGS) -c $< -o $@

bonus: $(LIBFT) $(CHECKER)

clean:
	$(RM) -r $(OBJS_DIR)
	$(MAKE) clean -C $(FT_DIR)

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	$(MAKE) fclean -C $(FT_DIR)

re: fclean all

norm:
	@norminette $(SRCS_DIR) $(INCS_DIR) $(CHECKER_DIR)
