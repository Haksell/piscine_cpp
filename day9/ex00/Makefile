NAME := btc
PATH_OBJS := objs
CXX := c++ -Wall -Wextra -Werror -std=c++98 -g3
CLASSES := BitcoinExchange Date utils
SRCS := main.cpp ${addsuffix .cpp, ${CLASSES}}
HEADERS := ${addsuffix .hpp, ${CLASSES}}
OBJS := ${patsubst %.cpp, ${PATH_OBJS}/%.o, ${SRCS}}

all: ${NAME}

${OBJS}: ${PATH_OBJS}/%.o: %.cpp ${HEADERS}
	@mkdir -p ${PATH_OBJS}
	${CXX} -c $< -o $@

${NAME}: ${OBJS}
	${CXX} ${OBJS} -o $@

clean:
	rm -rf ${PATH_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re