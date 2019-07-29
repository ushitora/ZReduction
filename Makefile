CC = g++
CFLAGS = -Wall -O2 -std=c++11
PROGRAMS = Raghavan ZReduction

all: $(PROGRAMS)


Raghavan: Raghavan.cpp
	$(CC) $(CFLAGS) -o $@ $^

ZReduction: ZReduction.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o *~ $(PROGRAMS)
