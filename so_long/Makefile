# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 16:41:34 by iouardi           #+#    #+#              #
#    Updated: 2022/02/15 13:52:33 by iouardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=            so_long
TEST_FILE=        Test.c
FLAGS=            -Wall -Werror -Wextra
CC=                cc
LIBFT_FILES = here/ft_isalnum.c \
			here/ft_isdigit.c \
			here/ft_memmove.c \
			here/ft_atoi.c \
			here/ft_isalpha.c \
			here/ft_isprint.c \
			here/ft_memset.c \
			here/ft_strncmp.c \
			here/ft_bzero.c \
			here/ft_isascii.c \
			here/ft_strlcpy.c \
			here/ft_strnstr.c \
			here/ft_strrchr.c \
			here/ft_memcmp.c \
			here/ft_toupper.c \
			here/ft_tolower.c \
			here/ft_calloc.c \
			here/ft_strdup.c \
			here/ft_memchr.c \
			here/ft_strtrim.c \
			here/ft_itoa.c \
			here/ft_putchar_fd.c \
			here/ft_putstr_fd.c \
			here/ft_putnbr_fd.c \
			here/ft_putendl_fd.c \
			here/ft_substr.c \
			here/ft_strmapi.c \
			here/ft_split.c \
			here/ft_striteri.c \

SRC_FILES_BONUS = here/ft_lstnew_bonus.c \
				here/ft_lstadd_front_bonus.c \
				here/ft_lstlast_bonus.c \
				here/ft_lstadd_back_bonus.c \
				here/ft_lstlast_bonus.c \
				here/ft_lstsize_bonus.c \
				here/ft_lstdelone_bonus.c \
				here/ft_lstclear_bonus.c \
				here/ft_lstiter_bonus.c
SRC_FILES = so_long.c
GNL_FILES = heeere/get_next_line.c heeere/get_next_line_utils.c
OBJ_FILES=			$(SRC_FILES:.c=.o)
OBJ_FILES_BONUS=	$(SRC_FILES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C here
	@cp here/libft.a ./
	$(CC) $(OBJ_FILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a $(GNL_FILES) -fsanitize=address -g

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

Bonus:  $(OBJ_FILES_BONUS)
	ar rcs $(NAME) $(OBJ_FILES_BONUS) 

