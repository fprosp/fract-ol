# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 20:32:19 by fprosper          #+#    #+#              #
#    Updated: 2023/02/13 21:39:47 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractal

MAIN			=	./fractol/main.c
LIBFT			=	./libft/libft.a
FT_PRINTF		=	./ft_printf/printf.a
FRACTLIB		=	./fractol/fractlib.a

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -lm

$(NAME):		
				make -C ./libft
				make -C ./ft_printf
				make -C ./fractol
				$(CC) $(CFLAGS) $(MLXFLG) $(MAIN) $(LIBFT) \
				$(FT_PRINTF) $(FRACTLIB) -o $(NAME)

all:			$(NAME)
				make clean

clean:			
				make clean -C ./libft
				make clean -C ./ft_printf
				make clean -C ./fractol
				$(RM) $(OBJS)

fclean:			clean
				make fclean -C ./libft
				make fclean -C ./ft_printf
				make fclean -C ./fractol
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re