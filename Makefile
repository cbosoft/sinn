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
SO = libsinn.so

obj/test%.o: src/test%.cpp $(HDR)
	mkdir -p `dirname $@`
	$(CXX) $(CFLAGS) $< -c -o $@

obj/%.o: src/%.cpp $(HDR)
	mkdir -p `dirname $@`
	$(CXX) $(CFLAGS) $< -c -fPIC -o $@

.PHONY: shared

shared: $(SO)

%.so: $(OBJ) $(HDR)
	$(CXX) $(CFLAGS) -shared $(OBJ) -o $(SO)

.PHONY: tests

tests: shared test1 test2
	cd tests && ./run_tests.sh

test1: obj/test1.o $(OBJ) $(HDR)
	$(CXX) $(CFLAGS) -L`pwd` $< $(OBJ) -o tests/$@ -lsinn $(LINK)

test2: obj/test2.o $(OBJ) $(HDR)
	$(CXX) $(CFLAGS) -L`pwd` $< $(OBJ) -o tests/$@ -lsinn $(LINK)


clean:
	rm -rf obj $(EXE)
