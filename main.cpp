#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <functional>

#include <cstdlib>
#include <ctime>                // for gettimeofday()

#include "command.h"
#include "device.h"

using namespace std;

int main(int argc, char *argv[]){
	if(argc!=3){
		cerr<<"Usage: "<<argv[0]<<" <file> <device>"<<endl;
		exit(EXIT_FAILURE);
	}

	priority_queue<Command, vector<Command>, less<Command>> pq;

	ifstream ifs(argv[1], ios::in);

	unsigned int time;
	while(ifs>>time){
		string opcode;
		getline(ifs, opcode);
		pq.push({time, opcode});
	}

	struct timespec stime, now;
	clock_gettime(CLOCK_MONOTONIC, &stime);

	Device d(argv[2]);
	while(!pq.empty()){
		clock_gettime(CLOCK_MONOTONIC, &now);
		if((now.tv_sec*1000+now.tv_nsec/1.0e6 - (stime.tv_sec*1000+stime.tv_nsec/1.0e6))>pq.top().getTime()){
			cout<<"A Command Sent:"<<pq.top()<<endl;
			d<<pq.top();
			pq.pop();
		}
	}

	ifs.close();
	return EXIT_SUCCESS;
}
