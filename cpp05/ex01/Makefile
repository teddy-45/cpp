NAME	= form

RM		= rm -f

SRC		= Bureaucrat.cpp Form.cpp main.cpp \
        
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 # -g3  -fsanitize=address

OBJ		= $(SRC:.cpp=.o)

CPP		= c++

INCLUDE = Bureaucrat.hpp Form.hpp

all		: $(NAME)
            
%.o		: %.cpp $(INCLUDE)
		$(CPP) $(CPPFLAGS) -c $<  -o $@

$(NAME)	: $(OBJ)
		$(CPP) $(CPPFLAGS) $(OBJ) -o $@

clean	: 
		$(RM) $(OBJ)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

 