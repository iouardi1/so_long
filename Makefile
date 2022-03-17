# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 16:41:34 by iouardi           #+#    #+#              #
#    Updated: 2022/03/17 04:24:53 by iouardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=            so_long
TEST_FILE=        Test.c
FLAGS=            -Wall -Werror -Wextra
CC=                cc
SRC_FILES = mandatory/so_long.c \
			mandatory/draw_map.c \
			mandatory/read_the_map.c \
			mandatory/parsing_map.c \
			mandatory/initialize_check_parsing.c \
			mandatory/parsing_map2.c \
			mandatory/draw_player.c
GNL_FILES = mandatory/gnl/get_next_line.c \
			mandatory/gnl/get_next_line_utils.c
OBJ_FILES=			$(SRC_FILES:.c=.o)
OBJ_FILES_BONUS=	$(SRC_FILES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C mandatory/libft
	@cp mandatory/libft/libft.a ./
	$(CC) $(OBJ_FILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a $(GNL_FILES)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	find . -name "*.o" -delete
	find . -name "*.a" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

Bonus:
	make bonus -C ../bonus/
