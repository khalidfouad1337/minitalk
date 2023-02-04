SRCSS = server.c src/ft_printf.c src/ft_putchar.c src/ft_putnbr.c src/ft_putstr.c

SRCSC = client.c src/ft_atoi.c src/ft_printf.c src/ft_putchar.c src/ft_putnbr.c src/ft_putstr.c

OBGS = ${SRCSS:.c=.o}

OBGC = ${SRCSC:.c=.o}

NAME = server client

CC = gcc

AR = ar -rc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

%.o : %.c
		${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBGS} ${OBGC}
		${CC}  ${OBGS} -o server
		${CC}  ${OBGC} -o client

all : ${NAME}

clean :
		${RM} ${OBGS}
		${RM} ${OBGC}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re


