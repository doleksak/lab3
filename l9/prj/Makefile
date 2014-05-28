__start__: prog
	./prog

prog: sim.o main.o
	c++ main.o sim.o -o prog -lrt

sim.o: sim.cpp
	c++ -c sim.cpp -o sim.o

main.o: main.cpp
	c++ -c main.cpp -o main.o

clean:
	rm -f *.o prog