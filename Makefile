# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 15:48:36 by yoribeir          #+#    #+#              #
#    Updated: 2019/08/05 14:57:12 by yoribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in
INCLUDES	=	includes
HEADER		=	includes/lem_in.h
LIBS		=	libft
LIB			=	ft
FLAGS		=	-Wall -Werror -Wextra
DFLAGS		=	-g -g3 -fsanitize=address,undefined
SRCS		= 	bfs.c			\
				check_steps.c	\
				edmond.c		\
				error.c			\
				free.c			\
				hash.c			\
				init.c			\
				is_commands.c	\
				is_links.c		\
				is_rooms.c		\
				lem_in.c		\
 				opti.c			\
				options.c		\
				parse_links.c	\
				parse_rooms.c	\
				parser.c		\
				paths.c			\
				print_map.c		\
				print_sol.c		\
				queue.c			\
				solutions.c		\
				utils.c

LIBFTFILES =	ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memccpy.c	\
				ft_memmove.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strlen.c		\
				ft_strdup.c		\
				ft_strcpy.c		\
				ft_strncpy.c	\
				ft_strcat.c		\
				ft_strncat.c	\
				ft_strlcat.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strstr.c		\
				ft_strnstr.c	\
				ft_strcmp.c		\
				ft_strncmp.c	\
				ft_atoi.c		\
				ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c 	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_memalloc.c	\
				ft_memdel.c		\
				ft_strnew.c		\
				ft_strdel.c		\
				ft_strclr.c		\
				ft_striter.c	\
				ft_striteri.c	\
				ft_strmap.c		\
				ft_strmapi.c	\
				ft_strequ.c		\
				ft_strnequ.c	\
				ft_strsub.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_strsplit.c	\
				ft_itoa.c		\
				ft_putchar.c	\
				ft_putstr.c		\
				ft_putendl.c	\
				ft_putnbr.c		\
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putstr_fd.c 	\
				ft_putnbr_fd.c 	\
				ft_islower.c 	\
				ft_isupper.c 	\
				ft_isblanko.c 	\
				ft_lstnew.c 	\
				ft_lstdelone.c 	\
				ft_lstdel.c 	\
				ft_lstadd.c 	\
				ft_lstiter.c 	\
				ft_lstmap.c 	\
				ft_lstpushback.c\
				ft_lstsize.c 	\
				ft_lstat.c 		\
				ft_strndup.c 	\
				get_next_line.c \
				ft_printf.c 	\
				handlers.c 		\
				parsers.c 		\
				utils.c 		\
				handle_int.c 	\
				handle_unsigned.c \
				handle_char.c 	\
				handle_pointer.c\
				handle_escape.c \
				handle_string.c \
				handle_wchar.c 	\
				handle_float.c 	\
				ft_nblen.c 		\
				ft_tabdel.c 	\
				ft_strtoupper.c \
				ft_wstrlen.c 	\
				ft_abs.c 		\
				ft_strdigit.c

LIBFT		= $(patsubst %,$(LIBS)/%,$(LIBFTFILES))

SRCSREP		=	srcs
OBJS		=	$(SRCS:.c=.o)

BLANK		=	\x1b[0m
GREEN		=	\x1b[32;01m
RED			=	\x1b[31;01m
YELLOW		=	\x1b[38;5;228m

all: $(NAME)

%.o: $(SRCSREP)/%.c $(HEADER)
	@gcc $(FLAGS) -I$(INCLUDES) -o $@ -c $<

debug:
	@gcc $(DFLAGS) srcs/*.c libft/*.c -o $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJS) $(LIBFT)
	@echo "\n$(RED)CREATING LEM IN ...$(BLANK)"
	@make -C libft
	@gcc $(FLAGS) -I$(INCLUDES) $^ -L$(LIBS) -l$(LIB) -o $@
	@echo "$(GREEN)[lem-in created]$(BLANK)"

clean:
	@echo "\n$(RED)CLEANING OBJECTS FILES ...$(BLANK)"
	@rm -f $(OBJS)
	@make clean -C libft
	@echo "$(YELLOW)[object files removed]$(BLANK)"

fclean: clean
	@echo "\n$(RED)REMOVING LEM IN ...$(BLANK)"
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(YELLOW)[lem-in removed]$(BLANK)"

re: fclean all