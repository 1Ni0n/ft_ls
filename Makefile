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

SRC_FILE = ft_ls.c simplest_ls.c  args_controller.c\
check_for_illegal_opts.c ls_controller.c ls_recursive.c main_ls.c  check.c print_errors.c option_i_s_ff.c colors.c

OPT_L_FILES = option_l.c get_longest.c special_elem.c option_l_printing.c option_l_printing_controller.c\
option_l_printing_bis.c print_correct_date.c print_blocks_if_dir_full.c

OPT_L_DIR = option_l/

OPT_L = $(addprefix $(OPT_L_DIR), $(OPT_L_FILES))

ALL_OPT_L = $(addprefix $(SRC_DIR), $(OPT_L)) 

LISTS_FILES = lists_controller.c print_list.c sort_list.c sort_list_t.c

LISTS_DIR = lists/

LISTS = $(addprefix $(LISTS_DIR), $(LISTS_FILES))

ALL_LISTS = $(addprefix $(SRC_DIR), $(LISTS))

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILE))

OBJ = ft_ls.o simplest_ls.o lists_controller.o args_controller.o  print_list.o\
check_for_illegal_opts.o ls_controller.o ls_recursive.o main_ls.o sort_list.o option_l.o sort_list_t.o check.o get_longest.o special_elem.o\
option_l_printing.o option_l_printing_controller.o option_l_printing_bis.o print_correct_date.o print_blocks_if_dir_full.o print_errors.o option_i_s_ff.o colors.o

all: $(NAME)

$(NAME): lib $(LIB)
	@gcc $(FLAG) -c $(SRCS) $(ALL_OPT_L) $(ALL_LISTS)
	@gcc $(FLAG) $(OBJ) $(LIB) -o $(NAME)

lib:
	@make -C libft all

clean:
	@make -C libft clean
	@rm -f $(OBJ)

libclean:
	@make -C libft fclean

bigclean: clean libclean


fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

libfclean:
	@make -C libft fclean

fbigclean: fclean libfclean

re: fclean all
