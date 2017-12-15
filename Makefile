# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 12:37:29 by ggregoir          #+#    #+#              #
#    Updated: 2017/12/10 12:24:32 by ggregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= src/main.c src/errors.c src/utils.c src/opencl.c src/oclerror.c\
		  

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L libft/ -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework OpenCL -framework AppKit $(SRC) -o $(NAME)
	@echo '\033[92m[ ✔ ] \033[0m' "Fract'ol created " '\033[92m[ ✔ ] \n\033[0m'

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	@echo '\033[32m[ ✔ ] \033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	@echo '\033[32m[ ✔ ] \033[0m' "Lib Cleaned \n"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	@echo '\033[32m[ ✔ ] \033[0m' "Lib Fcleaned \n"

re: fclean all

test: re
	@echo '\033[32m\n\033[0m' "-------------------------------------"
	./fractol test

all: $(NAME)
.PHONY: clean fclean re all test