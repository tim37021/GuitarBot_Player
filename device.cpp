#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include <stdexcept>

#include "device.h"

using namespace std;

Device &operator<<(Device &d, const Command &cmd){
	int wcount = write(d.fd, cmd.getCode().data(), cmd.getCode().size()*sizeof(BYTE));
	if(wcount<0)
		throw runtime_error("Cannot write to serial port.");
	return d;
}

Device::Device(const string &device){
	fd=open(device.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
	if(fd==-1){
		throw runtime_error("No such file or directory.");
	}

	if (tcgetattr(fd, &serial) < 0)
		throw runtime_error("Getting configuration failed.");

	// Set up Serial Configuration
	serial.c_iflag = 0;
	serial.c_oflag = 0;
	serial.c_lflag = 0;
	serial.c_cflag = 0;

	serial.c_cc[VMIN] = 0;
	serial.c_cc[VTIME] = 0;

	serial.c_cflag = B9600 | CS8 | CREAD;

	tcsetattr(fd, TCSANOW, &serial); // Apply configuration`
}

Device::~Device(){
	close(fd);
}
