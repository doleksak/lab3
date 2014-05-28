__start__: prog
	./prog

prog: graf.o main.o timer.o
	c++ main.o graf.o timer.o -o prog -lrt

graf.o: graf.cpp
	c++ -c graf.cpp -o graf.o

timer.o: timer.cpp
	c++ -c timer.cpp -o timer.o

main.o: main.cpp
	c++ -c main.cpp -o main.o

clean:
	rm -f *.o prog