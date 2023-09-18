STD= -std=c++98
CFLAGS= -Wall -Wextra -Werror $(STD)
NAME= megaphone
MAIN= megaphone.cpp

all: $(MAIN)
	c++ $(MAIN) $(CFLAGS) -o $(NAME)

$(NAME): all

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
