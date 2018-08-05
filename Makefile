CXX := clang++
CXXFLAGS := -Wall -g
LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
LOCALDIR=/usr/local/Cellar/
srcfiles := $(shell find . -maxdepth 1 -name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

all: compile_and_build

compile_and_build: $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o build/reverie-woodsman $(objects) $(LIBS)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

include .depend
