all: structs.o main.o
		gcc -o struct structs.o main.o

structs.o: structs.c structs.h
		gcc -c structs.c
		
main.o: main.c
		gcc -c main.c
run:
		./struct
