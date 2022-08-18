NAME = minishell
CC = gcc  -lreadline #-fsanitize=address
# CFLAGS = -Werror -Wextra -Wall

SRC =  minishell.c

OBJ = ${SRC:.c=.o}
RM = rm -rf
all: ${NAME}
${NAME}: libft ${OBJ}
	${CC} libft/libft.a ${OBJ} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o  $@ 
libft: libft/libft.a
libft/libft.a:
	@${MAKE} -C libft
	@${MAKE} -C libft bonus
clean:
	@${MAKE} -C libft clean
	@${RM} ${OBJ}

fclean: clean
	@${MAKE} -C libft fclean
	@${RM} ${OBJ}
re : clean all