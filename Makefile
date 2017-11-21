NAME = fillit

SRCS = main.c init.c \
	   reader.c ttms_creator.c \
	   ttms.c backtracking.c \
	   print.c utils.c \
OBJS = $(SRCS:.c=.o)
INCLUDES = ./

CC = clang
FLAGS = -Wall -Werror -Wextra
RM = /bin/rm

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "Successfully created $(NAME)!"

%.o: %.c
	@echo "Creating object files..."
	$(CC) $(FLAGS) -I $(INCLUDES) -o $@ -c $<

all: $(NAME)

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
