NAME			= 42sh

$(shell mkdir -p .obj/src/readline 2> /dev/null)

CC				= gcc
CFLAGS			= #-Wall -Wextra -Werror 
INCLUDES		= -I./src/includes -I./libft/includes -I./src/readline
LIB				= -L./libft -lft -lncurses -lpthread

SRC 			= main.c\

READLINE	    = move.c\
				  winsize.c\
				  term_conf.c\
				  events.c\
				  cap.c\
				  input.c\
				  signal_conf.c\
				  del.c\
				  resize_screen.c\
				  start-end.c\
				  fword-bword.c\
				  visual.c\
				  visual_events.c\
				  v_move.c\
				  unselect.c\
				  copy.c\
				  paste.c\
				  cut.c\

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
