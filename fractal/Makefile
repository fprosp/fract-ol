# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 20:32:19 by fprosper          #+#    #+#              #
#    Updated: 2023/02/15 12:05:25 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fract-ol

MAIN			=	./fractol/main.c
LIBFT			=	./libft/libft.a
FT_PRINTF		=	./ft_printf/printf.a
FRACTLIB		=	./fractol/fractlib.a
MLX				=	./mlx_linux/libmlx.a
MLX_2			=	./mlx_linux/libmlx_Linux.a

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror 
MLXFLG			=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# MLXFLX mac: " -Lmlx -lmlx -framework OpenGL -framework AppKit"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):		
				make -C ./libft
				make -C ./ft_printf
				make -C ./fractol
				make -C ./mlx_linux
				$(CC) $(CFLAGS) $(MLXFLG) -o $(NAME) $(LIBFT) $(FT_PRINTF) \
				$(FRACTLIB) $(MLX) $(MLX_2) $(MAIN)

all:			$(NAME)
				make clean

clean:			
				make clean -C ./libft
				make clean -C ./ft_printf
				make clean -C ./fractol
				make clean -C ./mlx_linux
				$(RM) $(OBJS)

fclean:			clean
				make fclean -C ./libft
				make fclean -C ./ft_printf
				make fclean -C ./fractol
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re