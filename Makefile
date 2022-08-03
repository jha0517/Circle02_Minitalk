
NAME	= server

NAME2	= client

SRCS	= libft/ft_atoi.c server.c libft/ft_strlen.c src/ft_str_is_numeric.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c \
			libft/ft_putnbr_fd.c libft/ft_itoa.c

SRCS2	= libft/ft_atoi.c client.c libft/ft_strlen.c src/ft_str_is_numeric.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c\
			libft/ft_putnbr_fd.c libft/ft_itoa.c

OBJS	= ${SRCS:.c=.o}

OBJS2	= ${SRCS2:.c=.o}

CC		= cc

CFLAGS	= -Wall -Werror -Wextra 

${NAME}: 	${OBJS} ${OBJS2}
			${CC} -o ${NAME} ${OBJS} ${CFLAGS}
			${CC} -o ${NAME2} ${OBJS2} ${CFLAGS}


all: 		${NAME}

clean:
			rm -f ${OBJS} ${OBJS2}

fclean: 	clean
			rm -f ${NAME}

re: 		fclean all

.PHONY: all clean fclean re
