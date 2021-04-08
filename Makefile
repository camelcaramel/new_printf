SRCS=parser.c util.c write_char.c write_hex.c write_num.c\
write_pointer.c write_string.c ft_printf.c write_util.c
OBJS=$(SRCS:.c=.o)
TARGET=libftprintf.a
MLIB=ar rc
CFLAGS= -Wall -Wextra -Werror
CC=gcc

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(MLIB) $(TARGET) $(OBJS)

%($(OBJS)) : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : clean fclean all re