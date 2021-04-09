CC=g++  # variable donnant le compilateur
CFLAGS= -Wall -pedantic -g # options de compilation
all: exe1 # règle pour tout reconstruire

SacaDosFractionnaire.o: SacaDosFractionnaire.cpp header.h
	$(CC) $(CFLAGS) -c SacaDosFractionnaire.cpp

SacaDosDynamicProgrammation.o: SacaDosDynamicProgrammation.cpp header.h
	$(CC) $(CFLAGS) -c SacaDosDynamicProgrammation.cpp

main.o: main.cpp header.h
	$(CC) $(CFLAGS) -c main.cpp

exe1: SacaDosFractionnaire.o SacaDosDynamicProgrammation.o main.o
	$(CC) $(CFLAGS) SacaDosFractionnaire.o SacaDosDynamicProgrammation.o main.o -o exe1

clean:
	rm -rf *.o
