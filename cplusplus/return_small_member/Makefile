CXXFLAGS=-W -Wall -pedantic -std=c++14 -O2 -MD -MP
EXECUTABLES=return_by_value return_by_reference baseline

all: $(EXECUTABLES)

return_by_value: return_by_value.o random_numbers.o
	$(CXX) -o $@ $^

return_by_reference: return_by_reference.o random_numbers.o
	$(CXX) -o $@ $^

baseline: baseline.o random_numbers.o
	$(CXX) -o $@ $^

clean:
	rm -f *.o *.d $(EXECUTABLES)

-include *.d
