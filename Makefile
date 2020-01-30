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

TESTS = \
				tests/linear_regression1 \
				tests/next_in_series1

LINK = 
SO = libsinn.so
.SECONDARY:

obj/test/%.o: src/test/%.cpp $(HDR)
	@echo -e "\u001b[36mASSEMBLING OBJECT $@\u001b[0m"
	mkdir -p `dirname $@`
	$(CXX) $(CFLAGS) $< -c -o $@

obj/%.o: src/%.cpp $(HDR)
	@echo -e "\u001b[33mASSEMBLING PIC OBJECT $@\u001b[0m"
	mkdir -p `dirname $@`
	$(CXX) $(CFLAGS) $< -c -fPIC -o $@

%.so: $(OBJ) $(HDR)
	@echo -e "\u001b[34mLINKING OBJECTS TO EXECUTABLE $@\u001b[0m"
	$(CXX) $(CFLAGS) -shared $(OBJ) -o $@

.PHONY: tests
tests: $(TESTS)
	cd tests && ./run_tests.sh

tests/%: obj/tests/%.o $(SO)
	@echo -e "\u001b[32mLINKING OBJECTS TO TEST EXECUTABLE $@\u001b[0m"
	echo $(CXX) $(CFLAGS) -L`pwd` $< -o $@ -lsinn $(LINK)
	$(CXX) $(CFLAGS) -L`pwd` $< -o $@ -lsinn $(LINK)

clean:
	rm -rf obj $(SO) $(TESTS)
