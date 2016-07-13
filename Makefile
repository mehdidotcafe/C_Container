##
## Makefile for myirc in /home/meddou_m/Projects/Perso/C_Container
##
## Made by meddou_m
## Login   <meddou_m@epitech.net>
##
## Started on  Sun May 22 20:42:47 2016 meddou_m
## Last update Wed Jul 13 21:37:32 2016 meddou_m
##

RM	= rm -f

NAME	= libc_container.a

CFLAGS	= -Wall -Wall -Werror

SRCS	= list.c \
	  map.c	\
	  stack.c

OBJS	= $(SRCS:.c=.o)


all:	$(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
