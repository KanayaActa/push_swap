# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 08:24:02 by miwasa            #+#    #+#              #
#    Updated: 2024/11/15 20:26:58 by miwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

DIR				= .
FT				= $(DIR)/libft
LIBFT			= $(FT)/libft.a
INCS_DIR		= $(DIR)/includes
SRCS_DIR		= $(DIR)/srcs
OBJS_DIR		= $(DIR)/objs

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
IDFLAGS			+= -I$(INCS_DIR) -I$(FT)

SRCS			= \
	$(addprefix $(SRCS_DIR)/, \
	main.c \
	push_swap.c \
	)

OBJS			= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

.PHONY: all clean fclean re test norm

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(FT)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)
	$(MAKE) clean -C $(FT)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(FT)

re: fclean all

norm: $(SRCS_DIR) $(INCS_DIR)
	@norminette $^
