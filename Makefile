main: main.o DtFecha.o
	g++ DtFecha.o main.o -o sistema

main.o: main.cpp

DtFecha.o: DtFecha.cpp

clean:
	rm -rf *.o sistema
	clear