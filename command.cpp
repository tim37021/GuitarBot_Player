#include "command.h"
#include <sstream>
#include <iomanip>

using namespace std;

ostream &operator<<(ostream &out, const Command &c){
	for(auto p=c.opcode.cbegin();p!=c.opcode.cend();++p)
		out<<" "<<hex<<setw(2)<<setfill('0')<<static_cast<int>(*p);
	return out;
}

Command::Command(unsigned int t, const string &str): time(t){
	stringstream ss(str);
	int value;
	while(ss>>hex>>value){
		opcode.push_back(value);
	}
}

bool Command::operator>(const Command &c) const {
	//Smaller time has greater priority
	return this->time<c.time;
}


bool Command::operator<(const Command &c) const {
	//Smaller time has greater priority
	return this->time>c.time;
}
