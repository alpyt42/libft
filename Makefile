NAME = libft.a

HEADERS = libft.h
SOURCES = $(shell find . -type f -name 'ft_*.c')
OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

all :	$(NAME)

$(NAME) : $(OBJECTS)
	$(AR) rcs $@ $^

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean 
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re