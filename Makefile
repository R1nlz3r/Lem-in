# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/12 19:59:07 by mapandel          #+#    #+#              #
#    Updated: 2017/09/12 06:36:54 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		lem-in

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror -Weverything

#			Sources

SRC =		sources/lem_in.c \
			sources/touch_t_lem_in.c \
			sources/touch_t_lem_in_2.c \
			sources/touch_t_lem_in_3.c \
			sources/touch_t_lem_in_4.c \
			sources/lem_in_parsing.c \
			sources/lem_in_parsing_2.c \
			sources/lem_in_checker.c \
			sources/lem_in_pathfinder.c \
			sources/lem_in_move_ants.c \
			sources/lem_in_display.c \

OBJ =		$(SRC:.c=.o)

INC =		includes

#			Library Path

LIBPATH =	libft/libft.a

LIBINC	=	libft/includes

#			Colors

DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

#			Main Rules

.PHONY: all re glu clean fclean

$(NAME):
	@cd libft; $(MAKE) -f Makefile
	@echo "$(CYA)--::Compil Lem-In::--$(DEF)"
	@make $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBPATH)

all: $(NAME)

re: fclean all

glu: fclean all clean

#			Compilation Rules

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -I $(LIBINC) -c -o $@ $^

#			Clean Rules

clean:
	@cd libft; $(MAKE) -f Makefile clean
	@echo "$(PUR)--::Binary Delection::--$(DEF)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)--::Executable and Library Delection::--$(DEF)"
	@rm -rf $(NAME) $(LIBPATH)
