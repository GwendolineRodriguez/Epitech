
NAME = RoverUnitTests

SRCS = \
	Engine.cpp \
	AtmosphereRegulator.cpp \
	Oxygenator.cpp \
	WaterReclaimer.cpp \
	RoverUnitTests.cpp

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -Wall -Wextra

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	@./$(NAME)

.PHONY: all clean fclean re test
