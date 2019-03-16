prog: main.o
	gcc -o simpleshell main.o

main.o: SimpleShell/main.c SimpleShell/shell_commands.h
	gcc -c SimpleShell/main.c SimpleShell/shell_commands.h
