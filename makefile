prog: main.o
	$(CC) -o ssl_dev main.o

main.o: SimpleShell/main.c
	$(CC) -c SimpleShell/main.c
