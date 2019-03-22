CC=gcc
DEPS=src/shell_commands.h
  
run: src/main.c
	$(CC) -o yss_dev src/main.c -lconfig
debug:
	$(CC) -g -o yss_dev src/main.c -lconfig
clean:
	rm yss_dev
