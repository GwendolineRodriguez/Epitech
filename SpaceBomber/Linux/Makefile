NAME	= SpaceBomber

CC	= g++

RM	= rm -f

CPPFLAGS	+= -I. -I./game/ -I./graph/ -I./game/Errors

CPPFLAGS 	+= -std=c++11 -lpthread -I./graph/graphirrKlang-64bit-1.5.0/include/ -I./graph/irrlicht-1.8.3/include/ -I/usr/X11R6/include  -O3 -ffast-math

SRCS	=	  	./Controller/Controller.cpp 					\
			main.cpp				\
			./graph/Score.cpp \
			./graph/Credits.cpp \
			./game/game.cpp 				\
			./graph/irrlicht.cpp			\
			./graph/MyEventReceiver.cpp		\
			./graph/MenuEventReceiver.cpp		\
			./graph/Splash.cpp			\
			./graph/Victory.cpp \
			./graph/Menu.cpp			\
			./graph/Controls.cpp			\
			./graph/Continue.cpp			\
			./graph/NewGame.cpp			\
			./game/Errors/Errors.cpp		\
			./game/Errors/game_errors.cpp	\
			./game/Errors/file_errors.cpp	\
			./game/Errors/Errors_thread.cpp\
			./game/HPlayer.cpp				\
			./game/APlayer.cpp				\
			./game/Bomb.cpp				\
			./game/Ia.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

install: lib $(NAME)

lib:
	unzip ./graph/lib.zip
	mv irrlicht-1.8.3 ./graph/
	mv irrKlang-64bit-1.5.0 ./graph/

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L./graph/irrlicht-1.8.3/lib/Linux/ -lIrrlicht -L"/usr/lib" ./graph/irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so -pthread -L/usr/X11R6/lib64 -lGL -lXxf86vm -lXext -lX11 -lXcursor

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
