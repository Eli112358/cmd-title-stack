#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <bits/stl_algo.h>
#include "stack.h"
using namespace std;
void add(string value) {
	ofstream ofs(getFile(),ios::app);
	if(!ofs.is_open()) {
		cout<<"Unable to open file: "<<getFile()<<'\n';
		return;
	}
	ofs.write(value.c_str(),value.npos);
	ofs.flush();
	ofs.close();
}
string get(int index) {
	ifstream ifs(getFile());
	if(!ifs.is_open()) {
		cout<<"Unable to open file: "<<getFile()<<'\n';
		return "";
	}
	string line;
	for(int i=0;getline(ifs,line);++i)
		if(i==index) {
			ifs.close();
			return line;
		}
	return "";
}
char *getFile() {
	return getenv("tStack");
}
string remove(int index) {
	string removed=get(index);
	ifstream ifs(getFile());
	if(!ifs.is_open()) {
		cout<<"Unable to open file: "<<getFile()<<'\n';
		return "";
	}
	vector<string> prev;
	string line;
	while(getline(ifs,line)) prev.push_back(line);
	ifs.close();
	ofstream ofs(getFile(),ios::trunc);
	if(!ofs.is_open()) {
		cout<<"Unable to open file: "<<getFile()<<'\n';
		return "";
	}
	for(int i=0;i<prev.size();++i)
		if(i!=index) {
			line=prev[i]+"\n";
			ofs.write(line.c_str(),line.size());
		}
	ofs.flush();
	ofs.close();
	return removed;
}
void show(int index) {
	cout<<get(index)<<'\n';
}
int stackSize() {
	ifstream ifs(getFile());
	if(!ifs.is_open()) {
		cout<<"Unable to open file: "<<getFile()<<'\n';
		return 0;
	}
	return (int)count(istreambuf_iterator<char>(ifs),istreambuf_iterator<char>(),'\n');
}
