CXXFLAGS=-W -Wall -pedantic -std=c++14 -O2 -MD -MP

main: main.o random_numbers.o
	$(CXX) -o $@ $^

clean:
	rm -f *.o *.d main

-include *.d
