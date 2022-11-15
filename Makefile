# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 15:07:12 by ale-cont          #+#    #+#              #
#    Updated: 2022/11/15 20:10:50 by ale-cont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_calloc.c ft_isdigit.c ft_memcmp.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_isalnum.c\
			ft_isprint.c ft_memcpy.c ft_split.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c\
			ft_isalpha.c ft_itoa.c ft_memmove.c ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_tolower.c\
			ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strdup.c ft_strlen.c ft_strrchr.c\
			ft_toupper.c ft_strmapi.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
			ft_putnbr_fd.c ft_itoa.c ft_striteri.c

OBJS = $(SOURCES:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c

OBJS_BON = $(BONUS:.c=.o)

NAME = libft.a
CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus : $(OBJS) $(OBJS_BON)
	$(AR) $(NAME) $(OBJS) $(OBJS_BON)

all :	$(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_BON)

fclean : clean 
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
