main: main.o DtFecha.o DtBarco.o DtBarcoPesquero.o DtBarcoPasajeros.o DtPuerto.o DtArribo.o
	g++ DtFecha.o main.o DtBarco.o DtBarcoPesquero.o DtBarcoPasajeros.o DtPuerto.o DtArribo.o -o sistema
	
DtPuerto.o: DtPuerto.cpp

DtArribo.o: DtArribo.cpp

DtBarcoPasajeros.o: DtBarcoPasajeros.cpp

DtBarcoPesquero.o: DtBarcoPesquero.cpp

DtBarco.o: DtBarco.cpp

main.o: main.cpp

DtFecha.o: DtFecha.cpp

clean:
	rm -rf *.o sistema
	clear