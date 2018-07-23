CC=clang++
CFLAGS=-c -Wall
LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LOCALDIR=/usr/local/Cellar/

all: compile_and_build

compile_and_build: main.o
	$(CC) -g -Wall main.o -o build/reverie-woodsman -L$(LOCALDIR) $(LIBS)

main.o: main.cpp
	$(CC) -g $(CFLAGS) main.cpp

clean:
	  rm -rf *o build/*
