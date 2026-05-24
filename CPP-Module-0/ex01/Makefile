NAME = phonebook

SRC = Contact.cpp PhoneBook.cpp main.cpp

CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all:
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
