CXX = g++
CFLAGS = -g -Wall -Wextra -std=c++17 -O0
OBJ = 
LINK = 
EXE = brainyboi

obj/%.o: src/%.cpp $(HDR)
	$(CXX) $(CFLAGS) $< -c -o $@

exe: obj/main.o $(OBJ) $(HDR)
	$(CXX) $(CFLAGS) obj/main.o $(OBJ) -o $(EXE) $(LINK)

build-and-run: exe
	./$(EXE)

clean:
	rm -rf obj $(EXE)
