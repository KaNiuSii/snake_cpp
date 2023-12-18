SRC=./src
OBJ=./obj
CXX=g++
CXXFLAGS=-g -Wall -pedantic -std=c++11
LDFLAGS=-lncurses
EXECUTABLE=snake

OBJECTS=$(OBJ)/main.o $(OBJ)/WindowManager.o $(OBJ)/Layer.o $(OBJ)/Drawable.o $(OBJ)/Instruction.o $(OBJ)/Background.o $(OBJ)/Vector2D.o $(OBJ)/Moveable.o $(OBJ)/EventHandler.o $(OBJ)/Snake.o $(OBJ)/Add.o

all: $(OBJ) $(EXECUTABLE)

$(OBJ):
	mkdir -p $(OBJ)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)


$(OBJ)/Vector2D.o: $(SRC)/Vector2D.cpp $(SRC)/Vector2D.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/Drawable.o: $(SRC)/Drawable.cpp $(SRC)/Drawable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/Moveable.o: $(SRC)/Moveable.cpp $(SRC)/Moveable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(OBJ)/EventHandler.o: $(SRC)/EventHandler.cpp $(SRC)/EventHandler.h $(SRC)/Moveable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/Add.o: $(SRC)/Add.cpp $(SRC)/Add.h $(SRC)/Add.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/Instruction.o: $(SRC)/Instruction.cpp $(SRC)/Instruction.h $(SRC)/Moveable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJ)/Snake.o: $(SRC)/Snake.cpp $(SRC)/Snake.h $(SRC)/Moveable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJ)/Background.o: $(SRC)/Background.cpp $(SRC)/Background.h $(SRC)/Drawable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/Layer.o: $(SRC)/Layer.cpp $(SRC)/Layer.h $(SRC)/Drawable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/WindowManager.h $(SRC)/Layer.h $(SRC)/Drawable.h $(SRC)/Vector2D.h $(SRC)/Instruction.h $(SRC)/Background.h $(SRC)/Snake.h $(SRC)/Add.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/WindowManager.o: $(SRC)/WindowManager.cpp $(SRC)/WindowManager.h $(SRC)/Layer.h $(SRC)/Drawable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	-rm -f $(EXECUTABLE)
	-rm -rf $(OBJ)
