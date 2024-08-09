NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC= $(addprefix sources/, $(SOURCES))
SOURCES = exec.c handlers.c main.c paths.c

OBJ_DIR = objects
OBJECTS= $(addprefix $(OBJ_DIR)/, $(SRC:sources/%.c=%.o))

LIBFT_PATH = ../libft
LIBFT= $(LIBFT_PATH)/libft.a

# Reset

Color_Off='\033[0m'       # Text Reset

IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
ICyan='\033[0;96m'        # Cyan

MSG1 = @echo ${IGreen}"Compiled Successfully ✔︎"${Color_Off}
MSG2 = @echo ${IYellow}"Cleaned Successfully ✔︎"${Color_Off}
MSG3 = @echo ${ICyan}"Cleaned ${NAME} Successfully ✔︎"${Color_Off}

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LIBFT)
	$(MSG1)
	
$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR)/%.o: sources/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	rm -f *.o
	$(MSG2)

fclean:	clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(OBJECTS)
	rmdir $(OBJ_DIR)
	$(MSG3)
	
re:	fclean all

.PHONY: all clean fclean re
