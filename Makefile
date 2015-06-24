CXX=g++
CXXFLAGS = -Wall -std=c++11

INCLUDES = -I./include -I./include/ResourceManager -I./include/StateManager
LIBS = -L./lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-res-man -lsfml-state-man

vpath %.o ./build
vpath %.h ./include:./include/ResourceManager:./include/StateManager
vpath %.cpp ./src:./src/ResourceManager:./src/StateManager

all: build foth tidy

.PHONY: clean build tidy

foth: Foth.o FothScreen.o PlayLevelState.o MaterialGrid.o TrackGrid.o TrackLayer.o Properties.o 
	$(CXX) $^ $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $@

%.o: %.cpp %.h
	$(CXX) -c $< $(CXXFLAGS) $(INCLUDES) $(LIBS)

build:
	if [ ! -d "./build" ]; then mkdir build; fi

tidy:
	if [ `ls -l *.o 2> /dev/null | wc -l` -ne 0 ]; then mv -f *.o ./build/; fi

clean:
	rm -f foth ./build/*.o
