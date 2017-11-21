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

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@echo "$(OBJS)"
	$(CC) -o $@ $^ -L $(LIBFT) -lft $(FLAGS)
	@echo "Successfully created $(NAME)!"

%.o: %.c
	@echo "Creating object files..."
	$(CC) -o $@ -c $< $(FLAGS) -I $(INCLUDES)

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
