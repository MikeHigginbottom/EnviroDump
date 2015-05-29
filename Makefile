all: enviro_dump

enviro_dump.c: debug.h

.PHONY: clean
clean:
	-rm enviro_dump