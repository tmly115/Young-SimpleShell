CC=gcc -std=c89
DEPS=src/shell_commands.h

run: src/main.c
	$(CC) -o yss_dev src/main.c -lconfig

debug:
	$(CC) -g -o yss_dev src/main.c -lconfig

# Execute this command how administrador
install: run
	mkdir /opt/yss
	cp yss_dev /usr/bin
	cp config.cfg /opt/yss

# Execute this command how administrator
clean:
	rm /usr/bin/yss_dev /opt/yss/config.cfg
