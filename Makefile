#    colors    #

BLACK=	$(shell tput -Txterm setaf 0)
RED=	$(shell tput -Txterm setaf 1)
GREEN=	$(shell tput -Txterm setaf 2)
WHITE=	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
END=	$(shell tput -Txterm sgr0)

#			#

NAME = cub3D

CC = cc

FLAGS = -Wall -Werror -Wextra -g3  -no-pie

MlX_FLAGS = -Lmlx -Imlx -lmlx -framework OpenGL -framework AppKit

SRC_PATH = ./srcs

LIBFTPATH = ./libft

FILES =	srcs/command/keyboard.c	 \
		srcs/mapping/draw_rect.c \
		srcs/mapping/init_pos.c  \
		srcs/main.c \
		srcs/raycasting/raycasting.c \



INCLUDES = -I/usr/include -lmlx -lft -I./includes

OBJ = $(FILES:.c=.o)

LIBFT = $(LIBFTPATH)/libft.a


LIBMLX = libmx_linux.a


all : $(LIBMLX)  $(LIBFT) $(NAME)

$(NAME) : 	$(OBJ)
			@$(CC) $(FLAGS)  $(OBJ) $(INCLUDES) -L $(LIBFTPATH) -lft -L ./mlx -lmlx -lXext -lX11 -o $(NAME) -lm
			@echo "$(GREEN)$(NAME) done ✅$(END)"

$(LIBMLX) :
			@make -C ./mlx

$(LIBFT) :
			@make -C $(LIBFTPATH)

%.o: %.c
		@$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
		@echo "$(BLUE)Compiling: $^$(END)"


clean :
			@make clean -C $(LIBFTPATH)
			@make clean -C ./mlx
			@rm $(foreach dir, $(SRC_PATH), $(dir)/*.o)
			@echo "$(RED)remove objects 🚮$(END)"

fclean : clean
			cd@make fclean -C $(LIBFTPATH)
			@rm $(NAME)
			@echo "$(RED)remove $(NAME) 🚮$(END)"

re:	fclean all
