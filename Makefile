NAME = minishell
CC = gcc  -lreadline #-fsanitize=address
# CFLAGS = -Werror -Wextra -Wall

SRC =  minishell.c parsing/lexer.c parsing/parser.c parsing/handle_herdoc.c parsing/get_next_line.c parsing/handle_expender.c parsing/handle_quote.c parsing/envp_conv_l.c parsing/test.c parsing/parsing.c

OBJ = ${SRC:.c=.o}
RM = rm -rf
all: ${NAME}
${NAME}: libft libftprintf ${OBJ}
	@${CC} libft/libft.a printf/libftprintf.a ${OBJ} -o ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o  $@ 
libft: libft/libft.a
libftprintf: printf/libftprintf.a
libft/libft.a:
	@${MAKE} -C libft
	@${MAKE} -C libft bonus
printf/libftprintf.a:
	@${MAKE} -C printf
clean:
	@${MAKE} -C libft clean
	@${MAKE} -C printf clean
	@${RM} ${OBJ}

fclean: clean
	@${MAKE} -C libft fclean
	@${MAKE} -C printf fclean
	@${RM} ${OBJ}
re : clean all