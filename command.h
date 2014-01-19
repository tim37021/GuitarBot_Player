#ifndef command_H_
#define command_H_

#include <ostream>
#include <string>
#include <vector>
#include "mytype.h"

class Command{
	friend std::ostream& operator<<(std::ostream &, const Command&);
	public:
		Command(unsigned int, const std::string &);
		~Command()=default;	
		bool operator>(const Command &) const;
		bool operator<(const Command &) const;

		const std::vector<BYTE> &getCode() const{
			return opcode;
		}

		unsigned int getTime() const{
			return time;
		}
	private:
		unsigned int time;
		std::vector<BYTE> opcode;
};

#endif
