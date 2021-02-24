# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 15:33:44 by madorna-          #+#    #+#              #
#    Updated: 2021/02/24 16:06:27 by madorna-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRCS		=	ft_strlen.s

SRCS_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
				ft_lstmap.c

OBJECTS		=	$(SRCS:.s=.o)

OBJS_BONUS	=	${SRCS_BONUS:.s=.o}

ifeq ($(shell uname),Linux)
	NASMFLAGS = -f elf64 -D__LINUX__=1
else
	NASMFLAGS = -f macho64
endif

%.o	: %.s
	nasm $(NASMFLAGS) $< -o $@

INCLUDES	=	./

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

bonus:			${OBJS} ${OBJS_BONUS}
				@ar rcs ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
				@rm -f $(OBJECTS) ${OBJS_BONUS}

fclean:			clean
				@rm -f $(NAME)
				@rm -f exec

re:				fclean all

main:			all
				@gcc -c -Wall -Wextra -Werror -lasm main.c -o exec

.PHONY:
				clean fclean all re bonus