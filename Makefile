CXX = g++
CXXFLAGS = -Werror=vla -std=c++14 -g -Wall -MMD
EXEC = chess 
OBJECTS = move.o player.o display.o moveGen.o emptyMoveGen.o board.o human.o computer.o pieceMoveGen.o levelOne.o levelTwo.o levelThree.o textDisplay.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
