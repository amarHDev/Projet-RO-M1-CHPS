CC=g++  # variable donnant le compilateur
CFLAGS= -Wall -pedantic -g # options de compilation
CF= -Wvla # ignorer les tableaux de tailles variables
CN= Wnarrowing
all: exe1 # règle pour tout reconstruire

SacaDosFractionnaire.o: SacaDosFractionnaire.cpp header.h
	$(CC) $(CFLAGS) -c SacaDosFractionnaire.cpp

SacaDosDynamicProgrammation.o: SacaDosDynamicProgrammation.cpp header.h
	$(CC) $(CFLAGS)  -c SacaDosDynamicProgrammation.cpp $(CF)

Backtracking.o: Backtracking.cpp header.h
	$(CC) -c Backtracking.cpp 

main.o: main.cpp header.h
	$(CC) $(CFLAGS) -c main.cpp

exe1: SacaDosFractionnaire.o SacaDosDynamicProgrammation.o Backtracking.o main.o
	$(CC) $(CFLAGS) SacaDosFractionnaire.o SacaDosDynamicProgrammation.o Backtracking.o main.o -o exe1

clean:
	rm -rf *.o
