
NAME	= server

NAME2	= server_val

SRCS	= libft/ft_atoi.c libft/ft_strlen.c libft/ft_str_is_numeric.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c \
			libft/ft_putnbr_fd.c libft/ft_itoa.c ft_printf/ft_convert_indicator.c ft_printf/ft_print_char.c \
			ft_printf/ft_print_uinteger.c ft_printf/ft_eval_format.c ft_printf/ft_print_hex.c \
			ft_printf/ft_printf.c ft_printf/ft_final_alignement_i.c ft_printf/ft_print_integer.c \
			ft_printf/ft_tolowerstr.c ft_printf/ft_initialize_tab.c ft_printf/ft_print_percent.c \
			ft_printf/ft_utoa.c ft_printf/ft_print_address.c ft_printf/ft_print_str.c ft_printf/ft_utoa_base.c\
			libft/ft_strchr.c libft/ft_memset.c src/outil.c libft/ft_strlcp.c libft/ft_calloc.c \
			libft/ft_bzero.c

SERVER	= server.c

SVR_O	= ${SERVER:.c=.o}

CLIENT	= client.c

CLT_O	= ${CLIENT:.c=.o}

OBJS	= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

${NAME}: 	${OBJS} ${SVR_O} ${CLT_O}
			${CC} -o ${NAME} ${OBJS} ${SVR_O} ${CFLAGS}
			${CC} -o client ${OBJS} ${CLT_O} ${CFLAGS}

all: 		${NAME}

clean:
			rm -f ${OBJS} ${SVR_O} ${CLT_O} 

fclean: 	clean
			rm -f ${NAME} client

re: 		fclean all


.PHONY: all clean fclean re
