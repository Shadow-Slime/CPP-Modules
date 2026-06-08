NAME = phonebook

SRC = Contact.cpp PhoneBook.cpp main.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
