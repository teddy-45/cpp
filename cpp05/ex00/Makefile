NAME	= bureau

RM		= rm -f

SRC		= Bureaucrat.cpp main.cpp \
        
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 # -g3  -fsanitize=address

OBJ		= $(SRC:.cpp=.o)

CPP		= c++

INCLUDE = Bureaucrat.hpp

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

