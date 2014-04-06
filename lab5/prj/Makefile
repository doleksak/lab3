__start__: asoc
	./asoc

asoc: asc.o main.o timer.o
	c++ main.o asc.o timer.o -o asoc -lrt

asc.o: asc.cpp
	c++ -c asc.cpp -o asc.o

timer.o: timer.cpp
	c++ -c timer.cpp -o timer.o

main.o: main.cpp
	c++ -c main.cpp -o main.o

clean:
	rm -f *.o asoc