# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epham <epham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 11:13:42 by yoribeir          #+#    #+#              #
#    Updated: 2019/10/16 13:22:49 by epham            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -I.

FILES =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_islower.c \
		ft_isupper.c \
		ft_isblanko.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstpushback.c \
		ft_lstsize.c \
		ft_lstat.c \
		ft_strndup.c \
		get_next_line.c \
		ft_printf.c \
		handlers.c \
		parsers.c \
		utils.c \
		handle_int.c \
		handle_unsigned.c \
		handle_char.c \
		handle_pointer.c \
		handle_escape.c \
		handle_string.c \
		handle_wchar.c \
		handle_float.c \
		ft_nblen.c \
		ft_tabdel.c \
		ft_strtoupper.c \
		ft_wstrlen.c \
		ft_abs.c \
		ft_strdigit.c

OBJ	= $(FILES:%.c=%.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?
	@echo "\033[1;34mLibft\t\033[1;33mCompilation\t\t\033[0;32m[OK]\033[0m"

clean:
	rm -f $(OBJ)
	@echo "\033[1;34mLibft\t\033[1;33mCleaning Objects\t\033[0;32m[OK]\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[1;34mLibft\t\033[1;33mCleaning Lib\t\t\033[0;32m[OK]\033[0m"

re: fclean all

.PHONY: clean fclean all re
