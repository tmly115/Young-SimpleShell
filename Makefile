VPATH := SimpleShell

.PHONY: clean

all: ssl_dev

ssl_dev: main.o
	$(CC) -o $@ $^

main.o: shell_commands.h

clean:
	$(RM) ssl_dev main.o
