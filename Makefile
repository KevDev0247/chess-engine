CXX = g++
CXXFLAGS = -Werror=vla -std=c++14 -g -Wall -MMD -L/opt/X11/lib -I/opt/X11/include -I/opt/X11/lib
EXEC = chess 
OBJECTS = graphicsDisplay.o window.o move.o player.o moveGen.o board.o human.o computer.o pieceMoveGen.o levelOne.o levelTwo.o levelThree.o textDisplay.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
