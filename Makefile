main: DtFecha.o DtBarco.o DtBarcoPesquero.o DtBarcoPasajeros.o DtPuerto.o DtArribo.o Barco.o BarcoPesquero.o BarcoPasajeros.o Puerto.o Arribo.o main.o
	g++ DtFecha.o DtBarco.o DtBarcoPesquero.o DtBarcoPasajeros.o DtPuerto.o DtArribo.o Barco.o BarcoPesquero.o BarcoPasajeros.o Puerto.o Arribo.o main.o -o sistema
	
DtFecha.o: DtFecha.cpp

DtBarco.o: DtBarco.cpp

DtBarcoPesquero.o: DtBarcoPesquero.cpp

DtBarcoPasajeros.o: DtBarcoPasajeros.cpp

DtPuerto.o: DtPuerto.cpp

DtArribo.o: DtArribo.cpp

Barco.o: Barco.cpp

BarcoPesquero.o: BarcoPesquero.cpp

BarcoPasajeros.o: BarcoPasajeros.cpp

Puerto.o: Puerto.cpp

Arribo.o: Arribo.cpp

main.o: main.cpp

clean:
	rm -rf *.o sistema
	clear
