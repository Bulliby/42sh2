NAME			= 42sh

$(shell mkdir -p .obj/src/readline 2> /dev/null)

CC				= gcc
CFLAGS			= #-Wall -Wextra -Werror 
INCLUDES		= -I./src/includes -I./libft/includes -I./src/readline
LIB				= -L./libft -lft -lncurses

SRC 			= main.c\

READLINE	    = move.c\
				  winsize.c\
				  term_conf.c\
				  events.c\
				  cap.c\
				  input.c\

READLINE_SRC	= $(addprefix readline/, $(READLINE))
			  

OBJ_PATH		= .obj/src/

OBJS        	= $(SRC:.c=.o) $(READLINE_SRC:.c=.o)
COMPILE     	= $(addprefix $(OBJ_PATH), $(OBJS))

all: $(NAME)

$(NAME): $(COMPILE)
	make -C libft
	$(CC) $(CFLAGS) $(COMPILE) $(INCLUDES) $(LIB) -o $(NAME)

$(OBJ_PATH)%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB) -o $@ -c $<

submodule:
	git submodule init libft
	git submodule update --remote libft

clean:
	rm -rf $(COMPILE)

fclean: clean
	rm -rf $(COMPILE) $(NAME)

re: fclean all
