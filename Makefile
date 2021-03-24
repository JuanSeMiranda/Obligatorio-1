main: main.o
	g++ main.o -o sistema

main.o: main.cpp

clean:
	rm -rf *.o sistema
	clear