# Makefile for simple client/server program.

CXX = g++
FLAGS = -std=c++11 -pedantic -Wall -Wextra
OBJ_FILES = socket.o server.o client.o print.o
DEBUG = -g

all: main

main: $(OBJ_FILES) main.cpp
	$(CXX) $(FLAGS) -o main $(OBJ_FILES) main.cpp

debug: FLAGS += $(DEBUG)
debug: main

print.o: print.cpp print.hpp
	$(CXX) $(FLAGS) -c print.cpp

client.o: client.cpp client.hpp socket.hpp
	$(CXX) $(FLAGS) -c client.cpp

socket.o: socket.cpp socket.hpp
	$(CXX) $(FLAGS) -c socket.cpp

server.o: server.cpp server.hpp client.hpp socket.hpp
	$(CXX) $(FLAGS) -c server.cpp

clean:
	rm -f *.o
