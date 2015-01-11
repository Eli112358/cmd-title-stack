#include <stdlib.h>
#include <stdio.h>
#include <bits/stringfwd.h>
#include <bits/basic_string.h>
using namespace std;
string get(int index);
string getName(int index);
void set(int index,char *value);
void show(int index);
string get(int index) {
	return getenv(getName(index).c_str());
}
string getName(int index) {
	char name[]="title";
	if(index>-1) name=name+index;
	return name;
}
void set(int index,string value) {
	string name=getName(index);
	string cmd="set ";
	cmd+='"'+name+'='+value+'"';
	system(cmd.c_str());
};
void show(int index) {
	printf(get(index).c_str());
}
