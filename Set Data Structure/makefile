all: build

build: main.o 
	g++ -std=c++11 -o exe main.o

main.o:
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o exe