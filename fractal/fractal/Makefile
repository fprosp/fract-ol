# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 21:16:00 by fprosper          #+#    #+#              #
#    Updated: 2023/02/13 21:37:09 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractlib.a

SRCS	=		plot_def.c win_life.c plt_exe.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re