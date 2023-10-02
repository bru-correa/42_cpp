STD = -std=c++98
CFLAGS = -Wall -Wextra -Werror $(STD) -I./
OBJ_DIR = obj
SRC_FILES = $(shell find ./ -type f -name '*.cpp')
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))
NAME = phonebook
MAIN = main.cpp
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all
VALGRIND += --track-origins=yes --quiet --tool=memcheck

# all: $(OBJ_DIR) $(OBJ_FILES) $(MAIN)
# 	c++ $(MAIN) $(CFLAGS) -o $(NAME)

all: $(OBJ_DIR) $(OBJ_FILES)
	c++ $(OBJ_FILES) -o $(NAME)

$(NAME): all

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
	c++ -c $< $(CFLAGS) -o $@

clean:
	@rm -rf obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run: all
	@./$(NAME)

runv: all
	@$(VALGRIND) ./$(NAME)

setup_dev:
	./setup_dev.sh
