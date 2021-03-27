main: main.o DtFecha.o DtBarco.o DtBarcoPesquero.o DtBarcoPasajeros.o DtPuerto.o DtArribo.o Barco.o BarcoPesquero.o BarcoPasajeros.o Puerto.o Arribo.o
	g++ DtFecha.o main.o DtBarco.o DtBarcoPesquero.o DtBarcoPasajeros.o DtPuerto.o DtArribo.o Barco.o BarcoPesquero.o BarcoPasajeros.o Puerto.o Arribo.o -o sistema
	
Barco.o: Barco.cpp

Puerto.o: Puerto.cpp

Arribo.o: Arribo.cpp

BarcoPesquero.o: BarcoPesquero.cpp

BarcoPasajeros.o: BarcoPasajeros.cpp
	
DtPuerto.o: DtPuerto.cpp

DtArribo.o: DtArribo.cpp

DtBarcoPasajeros.o: DtBarcoPasajeros.cpp

DtBarcoPesquero.o: DtBarcoPesquero.cpp

DtBarco.o: DtBarco.cpp

DtFecha.o: DtFecha.cpp

main.o: main.cpp

clean:
	rm -rf *.o sistema
	clear