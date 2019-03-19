VPATH := SimpleShell
CFLAGS := -g3

.PHONY: all clean

all: ssl_dev

ssl_dev: main.o
	$(CC) -o $@ $(LDFLAGS) $^

main.o: shell_commands.h

clean:
	$(RM) ssl_dev main.o
