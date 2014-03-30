__start__: program
	./program

program: quick.o timer.o main.o heap.o merge.o
	c++ main.o quick.o timer.o heap.o merge.o -o program -lrt

quick.o: quick.cpp
	c++ -c quick.cpp -o quick.o

timer.o: timer.cpp
	c++ -c timer.cpp -o timer.o

main.o: main.cpp
	c++ -c main.cpp -o main.o

heap.o: heap.cpp
	c++ -c heap.cpp -o heap.o

merge.o: merge.cpp
	c++ -c merge.cpp -o merge.o

clean:
	rm -f *.o