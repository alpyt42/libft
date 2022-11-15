# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 15:07:12 by ale-cont          #+#    #+#              #
#    Updated: 2022/11/15 13:03:19 by ale-cont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = libft.h
SOURCES = ft_calloc.c ft_isdigit.c ft_memcmp.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_isalnum.c \
			ft_isprint.c ft_memcpy.c ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c \
			ft_isalpha.c ft_itoa.c ft_memmove.c ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c \
			ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strdup.c ft_strlen.c ft_strrchr.c \
			ft_toupper.c ft_strmapi.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_itoa.c ft_striteri.c
SOURCES_BONUS = ft_lstnew.c ft_lstadd_front.c e ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c 

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BON = $(SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

all :	$(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $@ $^

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

bonus : $(OBJECTS) $(OBJECTS_BON)
		ar rcs $@ $^

clean :
	$(RM) $(OBJECTS)

fclean : clean 
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re
