CC=gcc
DEPS=src/shell_commands.h
  
run: src/main.c
	$(CC) -o ssl_dev src/main.c
debug:
	$(CC) -g -o ssl_dev src/main.c
clean:
	rm ssl_dev
