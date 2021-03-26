main: main.o DtFecha.o DtBarco.o DtBarcoPesquero.o
	g++ DtFecha.o main.o DtBarco.o DtBarcoPesquero.o -o sistema

DtBarcoPesquero.o: DtBarcoPesquero.cpp

DtBarco.o: DtBarco.cpp

main.o: main.cpp

DtFecha.o: DtFecha.cpp

clean:
	rm -rf *.o sistema
	clear