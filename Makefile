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
	@echo -e "\n\e[90mCompiling \e[0m$(NAME)\e[0m"
	@$(CC) -o $@ $(filter-out $<,$^) -L $(LIBFT) -lft $(FLAGS)
	@echo -e "\e[32mSuccessfully created \e[4;92m$(NAME)\e[32m!\e[0m"

%.o: %.c
	@echo -ne "\e[90mCreating object file \e[0m$@ "
	@$(CC) -o $@ -c $< $(FLAGS) -I $(INCLUDES)
	@echo -e "\e[32mdone!\e[0m"

libft:
	@echo -ne "\n\e[90mCompiling \e[0mlibft\e[0m "
	@make -C $(LIBFT) all > /dev/null
	@echo -e "\e[32mdone!\e[0m\n"

libft_fclean:
	@make -C $(LIBFT) fclean > /dev/null
	@echo -e "\e[33mRemoved \e[93mlibft objects and executable!\e[0m"

clean:
	@$(RM) -f $(OBJS)
	@echo -e "\e[33mRemoved \e[93mobject files!\e[0m"

fclean: clean
	@$(RM) -f $(NAME)
	@echo -e "\e[33mRemoved \e[93m$(NAME) executable!\e[0m"

re: fclean libft_fclean $(NAME)

.PHONY: all clean fclean re libft libft_fclean
