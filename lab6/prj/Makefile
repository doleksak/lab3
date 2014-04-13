__start__: asoc
	./asoc

asoc: asc.o main.o timer.o drzewo.o hasz.o
	c++ main.o asc.o timer.o drzewo.o hasz.o -o asoc -lrt

asc.o: asc.cpp
	c++ -c asc.cpp -o asc.o

timer.o: timer.cpp
	c++ -c timer.cpp -o timer.o

drzewo.o: drzewo.cpp
	c++ -c drzewo.cpp -o drzewo.o

hasz.o: hasz.cpp
	c++ -c hasz.cpp -o hasz.o

main.o: main.cpp
	c++ -c main.cpp -o main.o

clean:
	rm -f *.o asoc