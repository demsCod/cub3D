#    colors    #

BLACK=	$(shell tput -Txterm setaf 0)
RED=	$(shell tput -Txterm setaf 1)
GREEN=	$(shell tput -Txterm setaf 2)
WHITE=	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
END=	$(shell tput -Txterm sgr0)

#			#


CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

OBJDIR = objs/


NAME = libft.a


all: $(NAME)

$(NAME): $(OBJS) $(SRCS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) done !✅$(END)"

%.o : %.c
	@$(CC) $(CFLAGS) -c -include ./libft.h $< -o $@
	@echo "$(BLUE)compiling: $^$(END)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
clean:
	@rm -rf $(OBJS)
	@echo "$(RED)remove objects 🚮$(END)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)remove $(NAME) 🚮$(END)"

re: fclean all

.PHONY: all clean fclean re