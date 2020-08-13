CC = gcc -Wall
CFLAGS = -c -g
EXE = scriptboy

all: output rmdotos

run:
	./$(EXE)

# install: output rmdotos

output: main.o argumentparser.o file_maker.o common.o err.o 
	$(CC) main.o argumentparser.o file_maker.o common.o err.o -o $(EXE)

main.o: main.c
	$(CC) $(CFLAGS) main.c

common.o: lib/common.c lib/common.h
	$(CC) $(CFLAGS) lib/common.c

argumentparser.o: lib/argumentparser.c lib/argumentparser.h
	$(CC) $(CFLAGS) lib/argumentparser.c	

file_maker.o: lib/file_maker.c lib/file_maker.h
	$(CC) $(CFLAGS) lib/file_maker.c	

err.o: lib/err.c lib/err.h
	$(CC) $(CFLAGS) lib/err.c

clean:
	rm -rf *.o $(EXE)

rmdotos:
	rm -fr *.o