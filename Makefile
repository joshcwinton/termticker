main: main.o funcs.o
	g++ -o main main.o funcs.o

main.o: main.cpp funcs.h
	g++ -c main.cpp

funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

clean:
	rm -f main *.csv *.o *.txt
