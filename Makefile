# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:02:14 by aibn-che          #+#    #+#              #
#    Updated: 2024/02/19 16:31:58 by aibn-che         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MSRCS =	./utils/get_next_line.c ./utils/get_next_line_utils.c ./utils/ft_itoa.c ./mandatory/arr_utils.c	\
		./mandatory/cordinations.c ./mandatory/movements.c ./mandatory/parsing_1.c ./mandatory/parsing_2.c ./mandatory/render_pixels_1.c	\
		./mandatory/render_pixels_2.c ./mandatory/render_pixels_3.c ./mandatory/struct_utils.c ./mandatory/check_xpm.c ./mandatory/so_long.c

BSRCS = 	./so_long_bonus/enemy_animation_and_movements.c ./so_long_bonus/movements.c ./so_long_bonus/check_xpm_bonus.c	\
			./so_long_bonus/parsing.c ./so_long_bonus/render_pixels.c ./so_long_bonus/so_long_bonus.c ./utils/get_next_line.c	\
			./utils/get_next_line_utils.c ./utils/ft_itoa.c ./so_long_bonus/arr_utils.c ./so_long_bonus/cordinations.c ./so_long_bonus/parsing_2.c 	\
			./so_long_bonus/render_pixels_1.c ./so_long_bonus/render_pixels_2.c ./so_long_bonus/struct_utils.c

NAME = so_long

BONUS_NAME = so_long_bonus_

MOBJS = $(MSRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

rm = rm -f

HEADERS = mandatory/so_long.h ./utils/get_next_line.h
HEADERS_2 = ./so_long_bonus/so_long_bonus.h ./utils/get_next_line.h

all : $(NAME)

mandatory/%.o: mandatory/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

so_long_bonus/%.o: so_long_bonus/%.c $(HEADERS_2)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):  $(MOBJS)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(BONUS_NAME): $(BOBJS)
	$(CC) $(CFLAGS) $^  -lmlx -framework OpenGL -framework AppKit -o $(BONUS_NAME)

bonus : $(BONUS_NAME)

clean :
	$(rm) $(MOBJS) $(BOBJS)

fclean : clean
	$(rm) $(NAME) $(BONUS_NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
