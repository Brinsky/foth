CXX=g++
CXXFLAGS = -Wall -std=c++11

INCLUDES = -I./include -I./include/ResourceManager -I./include/StateManager
LIBS = -L./lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-res-man -lsfml-state-man

vpath %.o ./build
vpath %.h ./include:./include/ResourceManager:./include/StateManager
vpath %.cpp ./src:./src/ResourceManager:./src/StateManager

all: foth 

.PHONY: clean

foth: Foth.cpp FothScreen.o Properties.o MaterialGrid.o TrackGrid.o TrackLayer.o PlayLevelState.o 
	$(CXX) $^ $(CXXFLAGS) $(LIBS) $(INCLUDES) -o $@
	rm -f *.o

%.o: %.cpp %.h
	$(CXX) -c $< $(CXXFLAGS) $(LIBS) $(INCLUDES)
	if [ ! -d "./build" ]; then mkdir build; fi	
	cp $@ ./build

clean:
	rm -f foth ./build/*.o
