SRCS = src/ft_printf.c src/ft_putchar.c src/ft_putnbr.c src/ft_putstr.c src/ft_atoi.c
OBJS = $(SRCS:.c=.o)
NAME = client server
CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = client.o
SERVER_OBJ = server.o

CC = cc
AR = ar -rc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

src/%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(SERVER_OBJ) : $(SERVER_SRC)
	$(CC) $(CFLAGS) -c $^ -o $@

$(CLIENT_OBJ) : $(CLIENT_SRC)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS) $(SERVER_OBJ) $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(OBJS) -o server
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(OBJS) -o client

clean :
		$(RM) $(OBJS) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re


