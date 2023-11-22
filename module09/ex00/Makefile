#GENERAL OPTIONS
# C Compiler
CC := c++
# Compiler flags
CFLAGS := -Wall -Wextra -Werror -std=c++98
# Removal tool
RM := rm -rf


# PROGRAM
# Program name
NAME := btc

# Headers
HEADER_DIR := .
HEADER :=
H_INCLUDE := $(addprefix -I, $(HEADER_DIR))

# Sources
SRC_DIR := .
SRC :=

# Objects
OBJ_DIR := obj
OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# Inclusions:
INCLUDE := $(H_INCLUDE)

# Development
CFLAGS += -g
SRC := $(shell find . -name '*.cpp' -type f)
SRC_DIR := $(dir $(SRC))
SRC := $(notdir $(SRC))
OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
HEADER := $(shell find . -name '*.hpp' -type f)
H_INCLUDE := $(sort $(addprefix -I, $(dir $(HEADER))))
INCLUDE := $(H_INCLUDE)

# vpath
vpath    %.hpp    $(HEADER_DIR)
vpath    %.cpp    $(SRC_DIR)


# -----------------------RULES------------------------------------------------ #
.PHONY: all vg clean fclean re run

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT into the program NAME
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(INCLUDE)

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.cpp $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Run program using valgrind
vg: all
	@valgrind --quiet --leak-check=full --show-leak-kinds=all ./$(NAME)

# Clean: removes objects' directory
clean:
	$(RM) $(OBJ_DIR)

# Full clean: removes objects' directory and generated programs
fclean: clean
	$(RM) $(NAME)

# Remake: full cleans and runs 'all' rule
re: fclean all

# Run the program
run: all
	@./$(NAME)
