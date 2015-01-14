#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "stack.h"
using namespace std;
int help();
void replaceAll(string &str,const string &from,const string &to);
int main(int argc,char *argv[]) {
	if(argc>1&&(argv[1]=="/?"||argv[1]=="/help")) return help();
	string newTitle;
	for(int i=0;i<argc;i++) newTitle+=' '+argv[i];
	newTitle.erase(0);
	replaceAll(newTitle,"$prev",get(stackSize()-1));
	if(newTitle=="") for(int i=stackSize()-1;i>-1;--i) show(i); else {
		add(newTitle);
		newTitle="title "+newTitle;
		system(newTitle.c_str());
	}
	return 0;
}
int help() {
	printf("Usage:");
	printf("  pusht [new title]");
	printf("");
	printf("Sets the window title to [new tite] and adds it to the stack");
	printf("If no new title is specified (no args), then it displays the stack");
	printf("");
	return 0;
}
void replaceAll(string &str,const string &from,const string &to) {
	if(from.empty())
		return;
	size_t start_pos=0;
	while((start_pos=str.find(from,start_pos))!=std::string::npos) {
		str.replace(start_pos,from.length(),to);
		start_pos+=to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}
