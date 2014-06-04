__start__: prog
	./prog

prog: sap.o main.o
	c++ main.o sap.o -o prog -lrt

sap.o: sap.cpp
	c++ -c sap.cpp -o sap.o

main.o: main.cpp
	c++ -c main.cpp -o main.o

clean:
	rm -f *.o prog