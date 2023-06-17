NAME = minishell
CC = gcc   
CFLAGS = -Werror -Wextra -Wall
EMCC = emcc

SRC =  $(shell find . -name "*.c")

RD_LINE = -lreadline #-L /goinfre/aabouzid/.brew/opt/readline/lib -I /goinfre/aabouzid/.brew/opt/readline/include

OBJ = ${SRC:%.c=%.o}

RM = rm -rf

all: libft ${NAME}


# ----------------
libft/libft.a:
	make -C libft


emcc: 
	@${EMCC} -std=c99 -g ${SRC} -o ${NAME}.js ${RD_LINE}

${NAME}: libft/libft.a ${OBJ}
	@${CC} ${CFLAGS} libft/libft.a ${OBJ} -o ${NAME} ${RD_LINE}

# %.o: %.c
# 	@${CC} -c $< -o  $@ 

# this rules to Make libft.a 




# libft/libft.a:
# 	@${MAKE} -C libft
# 	@${MAKE} -C libft bonus


# -----------------
clean:
	@${MAKE} -C libft clean

	@${RM} ${OBJ}

fclean: clean
	@${MAKE} -C libft fclean

	@${RM} ${OBJ}
	@${RM} minishell
re : clean all