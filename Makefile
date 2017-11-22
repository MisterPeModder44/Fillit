NAME=  fillit
SRCS=  main.c			\
	   init.c			\
	   reader.c			\
	   ttms_creator.c	\
	   ttms.c			\
	   backtracking.c	\
	   print.c			\
	   utils.c			\

OBJS=  $(SRCS:.c=.o)
INCLUDES=./
LIBFT=libft/
CC=gcc
FLAGS=-Wall -Werror -Wextra
RM=/bin/rm

all: $(NAME)

$(NAME): libft $(OBJS)
	@printf "\n\033[90mCompiling \033[0m$(NAME)\033[0m\n"
	@$(CC) -o $@ $(filter-out $<,$^) -L $(LIBFT) -lft $(FLAGS)
	@printf "\033[32mSuccessfully created \033[4;92m$(NAME)\033[32m!\033[0m\n"

%.o: %.c
	@printf "\033[90mCreating object file \033[0m$@ "
	@$(CC) -o $@ -c $< $(FLAGS) -I $(INCLUDES)
	@printf "\033[32mdone!\033[0m\n"

libft:
	@printf "\n\033[90mCompiling \033[0mlibft\033[0m "
	@make -C $(LIBFT) all > /dev/null
	@printf "\033[32mdone!\033[0m\n\n"

libft_fclean:
	@make -C $(LIBFT) fclean > /dev/null
	@printf "\033[33mRemoved \033[93mlibft objects and executable!\033[0m\n"

clean:
	@$(RM) -f $(OBJS)
	@printf "\033[33mRemoved \033[93mobject files!\033[0m\n"

fclean: clean
	@$(RM) -f $(NAME)
	@printf "\033[33mRemoved \033[93m$(NAME) executable!\033[0m\n"

re: fclean libft_fclean $(NAME)

.PHONY: all clean fclean re libft libft_fclean
