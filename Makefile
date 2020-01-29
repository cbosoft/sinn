CXX = g++
CFLAGS = -g -Wall -Wextra -Werror -std=c++17 -O0
OBJ = \
	obj/neural_network.o \
	obj/nn_dot.o \
	obj/nn_print.o \
	obj/input_layer.o \
	obj/hidden_layer.o \
	obj/output_layer.o \
	obj/layer.o \
	obj/train.o \
	obj/input_neuron.o \
	obj/hidden_neuron.o \
	obj/activation_functions/identity.o \
	obj/activation_functions/lrelu.o \
	obj/util.o

LINK = 
EXE = sinn

obj/%.o: src/%.cpp $(HDR)
	mkdir -p `dirname $@`
	$(CXX) $(CFLAGS) $< -c -o $@

exe: obj/main.o $(OBJ) $(HDR)
	$(CXX) $(CFLAGS) obj/main.o $(OBJ) -o $(EXE) $(LINK)

build-and-run: exe
	./$(EXE)

tests: test1 test2
	cd tests && ./run_tests.sh

test1: obj/test1.o $(OBJ) $(HDR)
	$(CXX) $(CFLAGS) $< $(OBJ) -o tests/$@ $(LINK)

test2: obj/test2.o $(OBJ) $(HDR)
	$(CXX) $(CFLAGS) $< $(OBJ) -o tests/$@ $(LINK)


clean:
	rm -rf obj $(EXE)
