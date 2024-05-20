NAME = client
NAME1 = server
BNAME = client_bonus
BNAME1 = server_bonus
HEADER = minitalk.h
BHEADER = minitalk_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = helper.c client.c server.c
BSRCS = helper_bonus.c client_bonus.c server_bonus.c

OBJS = $(SRCS:.c=.o);
BOBJS = $(BSRCS:.c=.o);

all: $(NAME) $(NAME1)
bonus: $(BNAME) $(BNAME1)

$(NAME): client.o
	$(CC) $(CFLAGS) $^ -o $@

$(BNAME): client_bonus.o
	$(CC) $(CFLAGS) $^ -o $@

$(NAME1): server.o helper.o
	$(CC) $(CFLAGS) $^ -o $@

$(BNAME1): server_bonus.o helper_bonus.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER) $(BHEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(BOBJS)
fclean : clean
	$(RM) $(NAME) $(NAME1)
	$(RM) $(BNAME) $(BNAME1)

re: fclean all

.PHONY: clean norm