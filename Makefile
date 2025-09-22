# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvoisin <tvoisin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 09:43:50 by tvoisin           #+#    #+#              #
#    Updated: 2025/02/10 12:35:52 by tvoisin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = cc
CFLAGS   = -Wall -Wextra -Werror -Iinclude
NAME     = pipex

SRC_DIR  = src
OBJ_DIR  = obj

SRC_FILES = ft_split.c get_next_line.c get_next_line_utils.c ft_pipx_bonus.c \
            ft_pipex_utils_bonus.c tool.c tool_2.c tool_3.c

SRC  = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ  = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

bonus: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) src/ft_pipex_bonus.h Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS): $(OBJ) src/ft_pipex_bonus.h Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(BONUS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re