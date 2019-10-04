all: main.o
	gcc -pthread -o main main.o
main.o: main.c
	gcc -pthread -o main.o main.c
clean:
	rm -f main.o main