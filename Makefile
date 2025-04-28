# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 14:00:50 by rohta             #+#    #+#              #
#    Updated: 2025/04/28 14:34:11 by rohta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11 -lm
SRC = main.c initialize.c hook_event.c ft_atof.c error_log.c\
      draw_image.c calculate.c arg_check.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft
LIBFT_OBJ = $(LIBFT_DIR)/ft_*.o

INC = -I ./libft
LIB = -L $(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_OBJ):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re