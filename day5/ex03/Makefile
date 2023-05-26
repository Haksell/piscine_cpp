NAME := ex03
PATH_OBJS := objs
GARBAGE := *_shrubbery
CXX := c++ -Wall -Wextra -Werror -std=c++98
CLASSES := AForm Bureaucrat Intern PresidentialPardonForm RobotomyRequestForm ShrubberyCreationForm
SRCS := main.cpp ${addsuffix .cpp, ${CLASSES}}
HEADERS := ex03.hpp ${addsuffix .hpp, ${CLASSES}}
OBJS := ${patsubst %.cpp, ${PATH_OBJS}/%.o, ${SRCS}}

all: ${NAME}

${OBJS}: ${PATH_OBJS}/%.o: %.cpp ${HEADERS}
	@mkdir -p ${PATH_OBJS}
	${CXX} -c $< -o $@

${NAME}: ${OBJS}
	${CXX} ${OBJS} -o $@

clean:
	rm -rf ${PATH_OBJS} ${GARBAGE}

fclean: clean
	rm -f ${NAME}

re: fclean
	${MAKE} ${NAME}

.PHONY: all clean fclean re