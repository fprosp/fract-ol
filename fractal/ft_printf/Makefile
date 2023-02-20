# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 12:42:10 by fprosper          #+#    #+#              #
#    Updated: 2022/10/18 16:40:25 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= printf.a

SRCS		=	ft_printf.c ft_char_gest.c ft_conv_gest.c

OBJS		=	 $(SRCS:.c=.o)

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -I.

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re