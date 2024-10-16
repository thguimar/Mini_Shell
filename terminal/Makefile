NAME 	= minishell

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror -g #-fsanitize=address

OBJ_DIR = objects
OBJECTS= $(SRC:sources/%.c=%.o)

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS 	=	minishell.c\
			../builtins/aux.c\
			../builtins/build_cd_utils1.c\
			../builtins/build_cd_utils2.c\
			../builtins/build_cd_utils3.c\
			../builtins/build_cd.c\
			../builtins/build_echo_utils.c\
			../builtins/build_echo.c\
			../builtins/build_env.c\
			../builtins/build_exit_utils.c\
			../builtins/build_exit.c\
			../builtins/build_export_utils1.c\
			../builtins/build_export_utils2.c\
			../builtins/build_export_utils3.c\
			../builtins/build_export.c\
			../builtins/build_pwd.c\
			../builtins/build_unset_utils.c\
			../builtins/build_unset.c\
			../builtins/builtins.c\
			../builtins/echo_expansioner.c\
			../builtins/expansions2.c\
			../signals/signals.c\
			commands.c\
			../libft/libft.a

Color_Off='\033[0m'       # Text Reset

IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
ICyan='\033[0;96m'        # Cyan

LINKS = $(LIBFT) -lreadline

MSG1 = @echo ${IGreen}"Compiled Successfully ✔︎"${Color_Off}
MSG2 = @echo ${IYellow}"Cleaned Successfully ✔︎"${Color_Off}
MSG3 = @echo ${ICyan}"Cleaned ${NAME} Successfully ✔︎"${Color_Off}

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) -o $@ $(LINKS) ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
	$(MSG1);

%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(OBJ_DIR)/%.o: sources/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	@rm -f *.o
	$(MSG2);

fclean: clean
	make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME) $(OBJECTS)
	$(MSG3);

re: fclean all
