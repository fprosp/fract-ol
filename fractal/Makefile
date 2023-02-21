# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 20:32:19 by fprosper          #+#    #+#              #
#    Updated: 2023/02/21 16:26:02 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol

MAIN			=	./fractal/main.c
LIBFT			=	./libft/libft.a
FT_PRINTF		=	./ft_printf/printf.a
FRACTLIB		=	./fractal/fractlib.a
MLX				=	./mlx/libmlx.a

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -lm
MLXFLG			=	-Lmlx -lmlx -framework OpenGL -framework AppKit

$(NAME):		
				make -C ./libft
				make -C ./ft_printf
				make -C ./fractal
				make -C ./mlx
				$(CC) $(CFLAGS) $(MLXFLG) -o $(NAME) $(LIBFT) \
				$(FT_PRINTF) $(FRACTLIB) $(MLX) $(MAIN)

all:			$(NAME)
				make clean

clean:			
				make clean -C ./libft
				make clean -C ./ft_printf
				make clean -C ./fractal
				make clean -C ./mlx
				$(RM) $(LIBFT) $(FT_PRINTF) $(FRACTLIB)

fclean:			clean
				make fclean -C ./libft
				make fclean -C ./ft_printf
				make fclean -C ./fractal
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re