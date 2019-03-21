CC=gcc
DEPS=src/shell_commands.h
  
run: src/main.c
	$(CC) -o yss_dev src/main.c
debug:
	$(CC) -g -o yss_dev src/main.c
clean:
	rm yss_dev
