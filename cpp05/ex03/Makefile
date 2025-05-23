NAME = form

RM = rm -f

SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

CPP = c++

INCLUDE = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

all		: $(NAME)

%.o		: %.cpp $(INCLUDE)
		$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
		$(CPP) $(CPPFLAGS) $(OBJ) -o $@


clean	:
		$(RM) $(OBJ) *_shrubbery

fclean	: clean
		$(RM) $(NAME)

re: fclean all
