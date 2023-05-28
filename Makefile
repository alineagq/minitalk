# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 19:39:40 by aqueiroz          #+#    #+#              #
#    Updated: 2023/04/15 15:09:49 by aqueiroz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

## COLORS DEFINITIONS

red:=$(shell tput setaf 1)
green:=$(shell tput setaf 2)
yellow:=$(shell tput setaf 3)
blue:=$(shell tput setaf 4)
purple:=$(shell tput setaf 5)
cyan:=$(shell tput setaf 6)
white:=$(shell tput setaf 7)
reset:=$(shell tput sgr0)

color-test:
	$(info $(red)Message$(reset))
	$(info $(green)Message$(reset))
	$(info $(yellow)Message$(reset))
	$(info $(blue)Message$(reset))
	$(info $(purple)Message$(reset))
	$(info $(cyan)Message$(reset))
	$(info $(white)Message$(reset))

NAME = minitalk
CLIENT = client
SERVER = server

SRC_PATH = srcs
LIB_PATH = libs
OBJ_PATH = objs
PATH_INC = includes
LIBFT_PATH = $(LIB_PATH)/libft

SERVER_FILES = server
CLIENT_FILES = client

SERVER_SRCS = $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(SERVER_FILES)))
CLIENT_SRCS = $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(CLIENT_FILES)))

OBJS = $(addsuffix .o, $(FILES))

# FLAGS

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -L./$(LIBFT_PATH) -lft

all: $(NAME)

LIBFT:
	@$(MAKE) -s -k -C $(LIBFT_PATH)
	$(info $(green)Libft installed!$(reset))

$(NAME): LIBFT $(SERVER) $(CLIENT)

$(SERVER):
	@$(CC) $(SERVER_SRCS) $(INCLUDE) $(LIBFLAGS) -o $@
	$(info $(purple)Server created. Run './server' to start.$(reset))

$(CLIENT):
	@$(CC) $(CLIENT_SRCS) $(INCLUDE) $(LIBFLAGS) -o $@
	$(info $(purple)Client created. Run './client {PID} {MESSAGE}' to start.$(reset))

valgrind:
	valgrind --track-origins=yes --error-exitcode=42 --leak-check=full --show-leak-kinds=all --quiet ./$(NAME) maps/42.fdf

clean:
	@rm -dfr ./objs
	@$(MAKE) -C $(LIBFT_PATH) --silent clean
	$(info $(yellow)All libs files were removed.$(reset))

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@$(MAKE) -C $(LIBFT_PATH) --silent fclean
	$(info $(yellow)Fdf file was removed.$(reset))

re: fclean all
	
.PHONY: all color-test clean fclean re