all: pontos.o arquivos.o
	gcc pontos.o arquivos.o main.c -o tp1

pontos.o: header.h
	gcc -c pontos.c

arquivos.o: header.h
	gcc -c arquivos.c

clean:
	rm -rf *.o

run:
	./main