# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 20:32:19 by fprosper          #+#    #+#              #
#    Updated: 2023/02/02 15:54:09 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractal

LIBFT			=	./libft/libft.a
FT_PRINTF		=	./ft_printf/printf.a
FRACTAL			= 	./fractal/fractol.a
OBJS			= $(SRCS:.c=.o)

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -Imlx -c

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C ./fractal
				make -C ./libft
				make -C ./ft_printf
				$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(FT_PRINTF) $(MAIN)


clean:			$(RM) $(OBJS)
				make clean -C ./fractal
				make clean -C libft
				make clean -C ft_printf

fclean:			clean 
				$(RM) $(NAME)
				make fclean -C ./fractal
				make fclean -C ./libft
				make fclean -C ./ft_printf
				

re:				fclean $(NAME)

.PHONY:			all clean fclean re