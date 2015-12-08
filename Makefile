# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscopel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/18 14:35:23 by lscopel           #+#    #+#              #
#    Updated: 2015/12/08 01:03:10 by lscopel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ft_minishell1

CFLAGS += -g -Wall -Werror -Wextra
RM = rm -rf

SRC_PATH = ./src/
SRC_NAME =	parse.c \
			builtin_env.c \
			builtin_exit.c \
			builtin_export.c \
			builtin_unset.c \
			builtin_cd.c \
			cmd_receive.c \
			cmd_clean.c \
			cmd_exec.c \
			env_building.c \
			env_set.c \
			error_cmd.c \
			lists.c \
			prompt_display.c \
			utils.c \
			main.c 
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC_PATH = ./includes/
INC = $(addprefix -I,$(INC_PATH))

LIBFT_PATH = ./libft/
LIBFT_NAME = libft.a
LIBFT_INC_PATH = ./libft/includes/
LIBFT = $(addprefix -L,$(LIBFT_PATH))
LIBFT_INC = $(addprefix -I,$(LIBFT_INC_PATH))

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(LIBFT_INC) $(INC) -o $@ -c $<
	@echo "Ok"

all: $(EXEC)

$(EXEC): $(LIBFT_PATH)$(LIBFT_NAME) $(OBJ)
	@$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LIBFT) -lft

$(LIBFT_PATH)$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re $(LIBFT_PATH)$(LIBFT_NAME)
