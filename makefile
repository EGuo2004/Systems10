all: structs.o
		gcc -o struct structs.o

structs.o: structs.c structs.h
		gcc -c structs.c
run:
		./struct
