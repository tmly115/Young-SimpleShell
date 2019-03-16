prog: main.o
	$(CC) -o ssl main.o

main.o: SimpleShell/main.c
	$(CC) -c SimpleShell/main.c
