CC=g++
CFLAGS=-Wall -Wextra
PT=python3

debug:
	for t in $(seq 1 100000); do echo "Running test $t"; ./gen $t > input; ./smart < input > smart_input; ./wrong < input > wrong_input; diff smart_input wrong_input || break; done

gen:
	$(CC) $(CFLAGS) gen.cpp -o gen
smart:
	$(CC) $(CFLAGS) smart.cpp -o smart
wrong:
	$(CC) $(CFLAGS) wrong.cpp -o wrong

all: gen smart wrong

rm_gen:
	rm -f gen
rm_smart:
	rm -f smart
rm_wrong:
	rm -f wrong
rm_all: rm_gen rm_smart rm_wrong

re: rm_all all