# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 21:59:24 by jubaldo           #+#    #+#              #
#    Updated: 2024/01/21 17:27:24 by jubaldo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

SRCS		=	srcs/builtins/cd.c 						\
				srcs/builtins/echo.c					\
				srcs/builtins/env.c 					\
				srcs/builtins/exit.c					\
				srcs/builtins/export.c					\
				srcs/builtins/pwd.c						\
				srcs/builtins/unset.c					\
				srcs/env/copy_env.c						\
				srcs/env/remove_env_var.c				\
				srcs/env/set_env_var.c					\
				srcs/env/update_env_var.c				\
				srcs/exec/exec_builtin.c				\
				srcs/exec/exec_command.c				\
				srcs/exec/execute.c						\
				srcs/exec/find_exec_path.c				\
				srcs/init/init_data.c					\
				srcs/init/init_env.c					\
				srcs/lexer/add_token.c					\
				srcs/lexer/handle_env_variables.c		\
				srcs/lexer/handle_pipes_redir.c			\
				srcs/lexer/handle_quotes.c				\
				srcs/lexer/handle_reg_char.c			\
				srcs/lexer/handle_whitespace.c			\
				srcs/lexer/token_input.c				\
				srcs/main/init_minishell.c				\
				srcs/main/main.c						\
				srcs/parser/check_token_order.c			\
				srcs/parser/expand_env.c				\
				srcs/parser/parse_command.c				\
				srcs/parser/parse_pipes_redirections.c	\
				srcs/parser/parse_reg_cmds.c			\
				srcs/pipes/close_pipes.c				\
				srcs/pipes/create_pipes.c				\
				srcs/pipes/exec_pipes_redirect.c		\
				srcs/pipes/setup_pipe_redir.c			\
				srcs/redirection/append.c				\
				srcs/redirection/heredoc.c				\
				srcs/redirection/input.c				\
				srcs/redirection/output.c				\
				srcs/redirection/redirection_handler.c	\
				srcs/signals/signal_handler.c			\
				srcs/utils/check_args.c					\
				srcs/utils/exit_minishell.c				\
				srcs/utils/get_prompt.c					\
				srcs/utils/free_all.c					\
				srcs/utils/input_handler.c				\
				srcs/utils/is_trucnuche.c				\
				srcs/utils/libft.c						\
				srcs/utils/libft2.c						\
				srcs/utils/libft3.c						\
				srcs/utils/libft4.c						\
				srcs/utils/path.c						\

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g

LFLAGS		=	-lreadline

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LFLAGS)
			@echo "\033[32m ~~ ./minishell successfully created! ~~"
			@echo "$$BIBOU"

clean:
			$(RM)
			rm -rf $(OBJS)
			@echo "\033[31m ~~ ./minishell successfully deleted! ~~"
			@echo "$$PQ"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[31m ~~ ./minishell successfully fdeleted! ~~"

re:			fclean all

.PHONY:		all clean fclean re

info: bibou
define BIBOU
           _       _     _          _ _ 
          (_)     (_)   | |        | | |
 _ __ ___  _ _ __  _ ___| |__   ___| | |
| '_ ` _ \| | '_ \| / __| '_ \ / _ \ | |
| | | | | | | | | | \__ \ | | |  __/ | |
|_| |_| |_|_|_| |_|_|___/_| |_|\___|_|_|
endef
export BIBOU

info: pq
define PQ

 .--""--.___.._
(  <__>  )     `-.
|`--..--'|      <|      cleaning  ....
|       :|       /
|       :|--""-./
`.__  __;' 
    ""
endef
export PQ
