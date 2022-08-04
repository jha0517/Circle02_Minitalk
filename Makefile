
NAME	= server

NAME2	= client

SRCS	= libft/ft_atoi.c server.c libft/ft_strlen.c libft/ft_str_is_numeric.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c \
			libft/ft_putnbr_fd.c libft/ft_itoa.c ft_printf/ft_convert_indicator.c ft_printf/ft_print_char.c \
			ft_printf/ft_print_uinteger.c ft_printf/ft_eval_format.c ft_printf/ft_print_hex.c \
			ft_printf/ft_printf.c ft_printf/ft_final_alignement_i.c ft_printf/ft_print_integer.c \
			ft_printf/ft_tolowerstr.c ft_printf/ft_initialize_tab.c ft_printf/ft_print_percent.c \
			ft_printf/ft_utoa.c ft_printf/ft_print_address.c ft_printf/ft_print_str.c ft_printf/ft_utoa_base.c\
			libft/ft_strchr.c libft/ft_memset.c

SRCS2	= libft/ft_atoi.c client.c libft/ft_strlen.c libft/ft_str_is_numeric.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c\
			libft/ft_putnbr_fd.c libft/ft_itoa.c ft_printf/ft_convert_indicator.c ft_printf/ft_print_char.c \
			ft_printf/ft_print_uinteger.c ft_printf/ft_eval_format.c ft_printf/ft_print_hex.c \
			ft_printf/ft_printf.c ft_printf/ft_final_alignement_i.c ft_printf/ft_print_integer.c \
			ft_printf/ft_tolowerstr.c ft_printf/ft_initialize_tab.c ft_printf/ft_print_percent.c \
			ft_printf/ft_utoa.c ft_printf/ft_print_address.c ft_printf/ft_print_str.c ft_printf/ft_utoa_base.c\
			libft/ft_strchr.c libft/ft_memset.c

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
			rm -f ${NAME} ${NAME2}

re: 		fclean all

.PHONY: all clean fclean re
