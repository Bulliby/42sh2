NAME		= 42sh

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./includes -I./libft/includes
LIB			= -L./libft -lft

$(shell mkdir .obj 2> /dev/null)

SRC 		= main.c
OBJ_PATH	= .obj/

OBJS        = $(SRC:.c=.o)
COMPILE     = $(addprefix $(OBJ_PATH), $(OBJS))

all: $(NAME)

$(NAME): $(COMPILE)
	make -C libft
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB) $(COMPILE) -o $(NAME)

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

submodule:
	git submodule init libft
	git submodule update --remote libft

clean:
	rm -rf $(COMPILE)

fclean: clean
	rm -rf $(COMPILE) $(NAME)

re: fclean all
