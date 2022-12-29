CC=g++
CFLAGS= -Wall -Wextra -Wpedantic -g
NAME =  huff
CNAME = huff.cpp
ONAME = huff.o

objs:
	$(CC) $(CFLAGS) -c $(CNAME)

all: objs
	$(CC) $(CFLAGS) $(ONAME) -o $(NAME)

all_objs_delete:
	find . -type f -name '*.o' -exec rm {} +
executables_delete:
	find . -type f -executable -exec rm {} +
compressed_delete:
	find . -type f -name '*.comp' -exec rm {} +
comp_delete:
	find . -type f -name '*.cmp' -exec rm {} +

delete: all_objs_delete executables_delete comp_delete compressed_delete