# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 20:32:19 by fprosper          #+#    #+#              #
#    Updated: 2023/02/20 19:52:29 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fract-ol

MAIN			=	./fractol/main.c
LIBFT			=	./libft/libft.a
FT_PRINTF		=	./ft_printf/printf.a
FRACTLIB		=	./fractol/fractlib.a
MLX				=	./mlx/libmlx.a

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -lm
MLXFLG			=	-Lmlx -lmlx -framework OpenGL -framework AppKit

$(NAME):		
				make -C ./libft
				make -C ./ft_printf
				make -C ./fractol
				make -C ./mlx
				$(CC) $(CFLAGS) $(MLXFLG) -o $(NAME) $(LIBFT) \
				$(FT_PRINTF) $(FRACTLIB) $(MLX) $(MAIN) 

all:			$(NAME)
				make clean

clean:			
				make clean -C ./libft
				make clean -C ./ft_printf
				make clean -C ./fractol
				make clean -C ./mlx
				$(RM) $(LIBFT) $(FT_PRINTF) $(FRACTLIB)

fclean:			clean
				make fclean -C ./libft
				make fclean -C ./ft_printf
				make fclean -C ./fractol
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re