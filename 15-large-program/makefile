fmt: fmt.o word.o line.o
	gcc -o fmt fmt.o word.o line.o

fmt.o: fmt.c word.h line.h
	gcc -c fmt.c

word.o: word.c word.h
	gcc -c word.c

line.o: line.c line.h
	gcc -c line.c
