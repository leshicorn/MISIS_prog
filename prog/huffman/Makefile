CC=g++
CFLAGS= -Wall -Wextra -Wpedantic -g
NAME =  main
CNAME = main.cpp
ONAME = main.o
LIBNAME = cmp.cpp
OLIBNAME = cmp.o

objs:
	$(CC) $(CFLAGS) -c $(CNAME) $(LIBNAME)

all: objs
	$(CC) $(CFLAGS) $(ONAME) $(OLIBNAME) -o $(NAME)

all_objs_delete:
	find . -type f -name '*.o' -exec rm {} +
executables_delete:
	find . -type f -executable -exec rm {} +

delete: all_objs_delete executables_delete