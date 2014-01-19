GuitarBot Player
	This is a GuitarBot player written in C++. It can read and play timeline file created by PI_GuitarBot.
	The application originally resides in Raspberry PI; however, you can compile and run it on any UNIX-like environment with compiler that support C++11.
[-] Timeline file format
	Timeline file is a text file. On each line, the first number denote when to send the commands in millisecond. The remaining is a series of commands in hex. And this file is probably unsorted.
[-] Commands
	String number from 0 to 5, and fret number from 0 to 5(0 means open string)
	Move string <i> to fret <j> - 0xij
	Press string <i> - 0xi6
	Release string <i> - 0xi7
	Pick string <i> - 0xi8
	strum chord from string <i> to string <j> - 0x(A+i)(A+j)
		ex: strumming from string 1 to string 6 is 0xAF
