CXX = g++
CFLAGS = -g -Wall -Wextra -std=c++17 -O0
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

clean:
	rm -rf obj $(EXE)
