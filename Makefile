NAME = minishell
CC = gcc   
CFLAGS = -Werror -Wextra -Wall


SRC =  minishell.c parsing/lexer.c parsing/parser.c parsing/handle_herdoc.c parsing/handle_expender.c parsing/handle_quote.c \
		parsing/envp_conv_l.c parsing/test.c parsing/parsing.c  parsing/concatinate_node.c parsing/expend_condition.c parsing/child_herdoc.c \
		execution/execution.c execution/builtins_functions.c execution/t_env.c execution/t_env_2.c execution/ft_cd.c execution/ft_echo.c \
		execution/ft_env.c execution/ft_exit.c execution/ft_export.c execution/ft_pwd.c execution/ft_unset.c execution/export_functions.c \
		execution/child_env_var.c execution/exec_builtins.c execution/functions.c execution/in_out_files.c execution/pipes.c execution/lonely.c \
		execution/norm.c execution/builtins_func.c

RD_LINE = -lreadline -L /goinfre/aabouzid/.brew/opt/readline/lib -I /goinfre/aabouzid/.brew/opt/readline/include

OBJ = ${SRC:.c=.o}

RM = rm -rf

all: ${NAME}

${NAME}: libft ${OBJ}
	@${CC} ${CFLAGS} ${RD_LINE} libft/libft.a ${OBJ} -o ${NAME}

%.o: %.c
	@${CC} -I /goinfre/aabouzid/.brew/opt/readline/include -c $< -o  $@ 

# this rules to Make libft.a 
# ----------------
libft: libft/libft.a



libft/libft.a:
	@${MAKE} -C libft
	@${MAKE} -C libft bonus


# -----------------
clean:
	@${MAKE} -C libft clean

	@${RM} ${OBJ}

fclean: clean
	@${MAKE} -C libft fclean

	@${RM} ${OBJ}
	@${RM} minishell
re : clean all