APP=RRT
CPPFLAGS=-Iinc -W -Wall -pedantic
LDFLAGS= -lm

__start__: all
	rm -f core.* core; ./${APP}

all: ${APP}

./${APP}: obj/Main.o obj/RRT.o obj/State.o obj/Model.o
	g++ ${LDFLAGS} -o ./${APP} obj/Main.o obj/RRT.o obj/State.o obj/Model.o

obj/Main.o: src/Main.cpp inc/RRT.hh
	g++ -c ${CPPFLAGS} -o obj/Main.o src/Main.cpp

obj/RRT.o: src/RRT.cpp inc/RRT.hh inc/State.hh inc/Model.hh
	g++ -c ${CPPFLAGS} -o obj/RRT.o src/RRT.cpp

obj/State.o: src/State.cpp inc/State.hh
	g++ -c ${CPPFLAGS} -o obj/State.o src/State.cpp

obj/Model.o: src/Model.cpp inc/Model.hh inc/State.hh
	g++ -c ${CPPFLAGS} -o obj/Model.o src/Model.cpp

clean:
	rm -f obj/*.o ./${APP} core.* core
