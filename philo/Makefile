NAME = philo

CC = cc

SRC =	src/main.c src/philo.c src/init.c \
		src/utils.c src/parsing.c src/monitoring.c

OBJ = $(SRC:.c=.o)

INCLUDES = includes/

CFLAGS := -Wall -Wextra -Werror -g3

BLUE = \033[1;36m
GREEN = \033[1;32m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e '$(BLUE)Linking executable$(NC)'
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I$(INCLUDES)
	@echo -e '$(GREEN)Executable ./$(NAME) linked successfully$(NC)'
	@printf "\033[38;2;150;255;150m\n██████╗░██╗░░██╗██╗██╗░░░░░░█████╗░\n"
	@printf "\033[38;2;125;255;175m██╔══██╗██║░░██║██║██║░░░░░██╔══██╗\n"
	@printf "\033[38;2;100;255;200m██████╔╝███████║██║██║░░░░░██║░░██║\n"
	@printf "\033[38;2;75;255;225m██╔═══╝░██╔══██║██║██║░░░░░██║░░██║\n"
	@printf "\033[38;2;50;255;250m██║░░░░░██║░░██║██║███████╗╚█████╔╝\n"
	@printf "\033[38;2;25;255;255m╚═╝░░░░░╚═╝░░╚═╝╚═╝╚══════╝░╚════╝░\n\n"


%.o: %.c
	@echo -e '$(BLUE)Compiling $<$(NC)'
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES)
	@echo -e '$(GREEN)Compiled $< successfully$(NC)'

clean:
	@echo -e '$(BLUE)Cleaning up object files$(NC)'
	@rm -rf $(OBJ)
	@echo -e '$(GREEN)Object files cleaned up successfully$(NC)'

fclean: clean
	@echo -e '$(BLUE)Cleaning up executable$(NC)'
	@rm -rf $(NAME)
	@echo -e '$(GREEN)Executable cleaned up successfully$(NC)'

re: fclean all

.PHONY: all clean fclean re
