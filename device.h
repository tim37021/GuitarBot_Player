#ifndef DEVICE_H_
#define DEVICE_H_

#include <string>
#include "command.h"
#include <termios.h>

class Device{
	friend Device&operator<<(Device &, const Command &);
public:
	Device(const std::string &device);
	~Device();
private:
	int fd;
	struct termios serial;
};

#endif
