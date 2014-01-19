CFLAGS=-std=c++0x -Wall
LFLAGS=-lrt

CmdPlayer: main.o command.o device.o
	g++ -o CmdPlayer main.o command.o device.o $(LFLAGS)
main.o: command.h main.cpp device.h
	g++ -c $(CFLAGS) main.cpp
command.o: command.h command.cpp
	g++ -c $(CFLAGS) command.cpp
device.o: device.cpp device.h
	g++ -c $(CFLAGS) device.cpp
clean:
	rm *.o CmdPlayer
