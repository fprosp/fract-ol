# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 21:16:00 by fprosper          #+#    #+#              #
#    Updated: 2023/02/20 19:40:20 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractlib.a

SRCS			=	plot_def.c mandelbrot.c julia.c \
					

OBJS			=	$(SRCS:.c=.o)

RM				=	rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re