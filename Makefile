CC=gcc
DEPS=SimpleShell/shell_commands.h
  
run: SimpleShell/main.c
	$(CC) -o ssl_dev SimpleShell/main.c
debug:
	$(CC) -g -o ssl_dev SimpleShell/main.c
clean:
	rm ssl_dev
