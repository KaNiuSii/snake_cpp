SRC=./src
OBJ=./obj
CXX=g++
CXXFLAGS=-g -Wall -pedantic -std=c++11
LDFLAGS=-lncurses
EXECUTABLE=snake

# Object files
OBJECTS=$(OBJ)/main.o $(OBJ)/WindowManager.o $(OBJ)/Layer.o $(OBJ)/Drawable.o $(OBJ)/Instruction.o $(OBJ)/Background.o $(OBJ)/Vector2D.o $(OBJ)/Moveable.o $(OBJ)/EventHandler.o $(OBJ)/Snake.o

# Default target
all: $(OBJ) $(EXECUTABLE)

# Create the obj directory
$(OBJ):
	mkdir -p $(OBJ)

# Executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)


# Compile Vector2D.cpp
$(OBJ)/Vector2D.o: $(SRC)/Vector2D.cpp $(SRC)/Vector2D.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Drawable.cpp
$(OBJ)/Drawable.o: $(SRC)/Drawable.cpp $(SRC)/Drawable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Drawable.cpp
$(OBJ)/Moveable.o: $(SRC)/Moveable.cpp $(SRC)/Moveable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Compile Instruction.cpp
$(OBJ)/EventHandler.o: $(SRC)/EventHandler.cpp $(SRC)/EventHandler.h $(SRC)/Moveable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Instruction.cpp
$(OBJ)/Instruction.o: $(SRC)/Instruction.cpp $(SRC)/Instruction.h $(SRC)/Moveable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Instruction.cpp
$(OBJ)/Snake.o: $(SRC)/Snake.cpp $(SRC)/Snake.h $(SRC)/Moveable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
# Compile Background.cpp
$(OBJ)/Background.o: $(SRC)/Background.cpp $(SRC)/Background.h $(SRC)/Drawable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Layer.cpp
$(OBJ)/Layer.o: $(SRC)/Layer.cpp $(SRC)/Layer.h $(SRC)/Drawable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile main.cpp
$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/WindowManager.h $(SRC)/Layer.h $(SRC)/Drawable.h $(SRC)/Vector2D.h $(SRC)/Instruction.h $(SRC)/Background.h $(SRC)/Snake.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile WindowManager.cpp
$(OBJ)/WindowManager.o: $(SRC)/WindowManager.cpp $(SRC)/WindowManager.h $(SRC)/Layer.h $(SRC)/Drawable.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
.PHONY: clean
clean:
	-rm -f $(EXECUTABLE)
	-rm -rf $(OBJ)
