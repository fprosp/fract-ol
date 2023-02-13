# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 20:32:19 by fprosper          #+#    #+#              #
#    Updated: 2023/02/09 18:43:59 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractal

LIBFT			=	./libft/libft.a
FT_PRINTF		=	./ft_printf/libftprintf.a
FRACTAL			= 	./fractal/fractol.a
OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -Imlx -c

$(NAME):		$(OBJS)
				make -C ./libft
				make -C ./ft_printf
				make -C ./fractal
				$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(FT_PRINTF)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all:			$(NAME)
				make clean

clean:			make clean -C ./fractal
				make clean -C libft
				make clean -C ft_printf
				$(RM) $(OBJS)

fclean:			clean
				make fclean -C ./fractal
				make fclean -C ./libft
				make fclean -C ./ft_printf
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re