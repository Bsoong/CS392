
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

CC = gcc

CFLAGS = -O0 -g -fPIC
LIBFLAGS =  -shared -fPIC

PROG = cs392_ass2
LIBS = libcs392string.so

$(PROG) : cs392_ass2_test.o $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBS): cs392_memcpy.o cs392_strlen.o
	$(CC) $(LIBFLAGS) -o $@ $^

clean:
	rm -rf *.o *.so $(PROG)

test:
	export LD_LIBRARY_PATH=$(shell pwd); ./$(PROG)
