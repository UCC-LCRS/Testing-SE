#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OSTYPE),cygwin)
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
else ifeq ($(OS),Windows_NT)
	CLEANUP = del /F /Q
	MKDIR = mkdir
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

# Herramientas
CC=gcc
CFLAGS=-I. -DTEST


#Files We Are To Work With
SRC = test.c bsp/bsp.c ../src/app.c unity.c
OBJ = $(patsubst %.c,%.o,$(SRC))
DEP = unity.h unity_internals.h
TGT = test$(TARGET_EXTENSION)

test:  $(TGT)
	./$(TGT)

%.o:: %.c $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@

%.o:: %.c $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@

$(TGT): $(OBJ)
	gcc -o $@ $^

clean:
	$(CLEANUP) *.o
	$(CLEANUP) $(TGT)

all: clean test

.PHONY: all
.PHONY: clean
.PHONY: test