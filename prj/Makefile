__start__: program
	./program

program: kolejka.o stos.o main.o
	c++ main.o kolejka.o stos.o -o program

kolejka.o: kolejka.cpp
	c++ -c kolejka.cpp -o kolejka.o

stos.o: stos.cpp
	c++ -c stos.cpp -o stos.o

main.o: main.cpp
	c++ -c main.cpp -o main.o
