# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguillot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/15 15:06:14 by aguillot          #+#    #+#              #
#    Updated: 2018/05/15 15:06:16 by aguillot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAG = -Werror -Wextra -Wall

LIB = libft/libft.a

SRC_DIR	= srcs/

SRC_FILE = ft_ls.c simplest_ls.c lists_controller.c args_controller.c  print_list.c check_for_illegal_opt.c ls_controller.c ls_recursive.c main_ls.c sort_list.c option_l.c print_list_l.c

SRCS =	$(addprefix $(SRC_DIR), $(SRC_FILE))

OBJ = ft_ls.o simplest_ls.o lists_controller.o args_controller.o  print_list.o check_for_illegal_opt.o ls_controller.o ls_recursive.o main_ls.o sort_list.o option_l.o print_list_l.o

all: $(NAME)

$(NAME): $(LIB)
	@gcc -c $(SRCS)
	@gcc $(FLAG) $(OBJ) $(LIB) -o $(NAME)

lib:
	@make -C libft all

clean:
	@rm -f $(OBJ)

libclean:
	@make -C libft fclean

bigclean: clean libclean


fclean: clean
	@rm -f $(NAME)

libfclean:
	@make -C libft fclean

fbigclean: fclean libfclean


re: lib fclean all
