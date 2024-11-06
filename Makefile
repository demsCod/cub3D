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

FLAGS = -Wall -Werror -Wextra -g3 

MlX_FLAGS = -Lmlx -Imlx -lmlx -framework OpenGL -framework AppKit

SRC_PATH = ./srcs

LIBFTPATH = $(SRC_PATH)/libft

SRCS = srcs/main.c	\
		srcs/parsing/parsing.c	\
		srcs/parsing/parsing_utils1.c	\
		srcs/parsing/infos_utils.c	\
		srcs/errors/print_errors.c	\
		srcs/errors/error_utils.c	\
		srcs/errors/free_and_exit.c	\
		srcs/raycasting/init_player_data.c \
		srcs/raycasting/casting_ray.c \
		srcs/raycasting/game_loop.c \
		srcs/raycasting/dda.c \
		srcs/raycasting/drawing.c \
		srcs/raycasting/pixel.c \
		srcs/keyboard/move_utils.c \
		srcs/keyboard/move_utils2.c \
		srcs/keyboard/move.c 

INCLUDES = -I/usr/include -lmlx -lft -I./includes

OBJ = $(SRCS:.c=.o)

LIBFT = $(LIBFTPATH)/libft.a

LIBMLX = libmx_linux.a

#	Loading bar	#

G                = \e[92m
X                 = \e[0m
BAR_SIZE        = 50

TAL_ddSRCS        := $(words $(SRCS))
MPILED_ddSRCS    := 0

#				#

all : $(LIBMLX)  $(LIBFT) $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(FLAGS)  $(OBJ) $(INCLUDES) -L $(LIBFTPATH) -lft -L ./mlx -lmlx -lXext -lX11 -lm -no-pie -o $(NAME)
		@echo
		@echo "$(GREEN)$(NAME) done ✅$(END)"

$(LIBMLX) :
		@make -sC ./mlx

$(LIBFT) :
		@make -sC $(LIBFTPATH)

%.o: %.c
	@$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
# @echo "$(BLUE)Compiling: $^$(END)"
	@$(eval MPILED_ddSRCS := $(shell echo $$(($(MPILED_ddSRCS)+1))))
	@echo -n " "
	@for i in `seq 1 $(shell echo "$$(($(MPILED_ddSRCS)*$(BAR_SIZE)/$(TAL_ddSRCS)))")`; do \
		echo -n "$(G)▰$(X)" ; \
	done
	@for i in `seq 1 $(shell echo "$$(($(BAR_SIZE)-$(MPILED_ddSRCS)*$(BAR_SIZE)/$(TAL_ddSRCS)))")`; do \
		echo -n "▱" ; \
	done
	@echo -n " [$(shell echo "scale=2; $(MPILED_ddSRCS)/$(TAL_ddSRCS) * 100" | bc)%] "
	@printf "\e[0K\r"


clean :
		@make clean -sC $(LIBFTPATH)
#		@make clean -C ./mlx
		@rm -f $(OBJ)
		@echo "$(RED)remove objects 🚮$(END)"

fclean : clean
		@make fclean -sC $(LIBFTPATH)
		@rm -f $(NAME)
		@echo "$(RED)remove $(NAME) 🚮$(END)"

s :
		@make -sC $(LIBFTPATH)
		@make all -s

re:	fclean all
