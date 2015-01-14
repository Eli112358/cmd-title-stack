#include <stdlib.h>
#include <string>
#include "stack.h"
using namespace std;
int main(int argc,char *argv[]) {
	if(stackSize()>0) {
		string cmd="title "+remove(stackSize()-1);
		system(cmd.c_str());
	}
	return 0;
}
