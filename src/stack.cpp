#include <stdlib.h>
#include <bits/stringfwd.h>
#include <bits/basic_string.h>
#include <iosfwd>
#include <bits/stl_algo.h>
#include <fstream>
#include <iostream>
using namespace std;
void add(string value);
string get(int index);
char *getFile();
string remove(int index);
void show(int index);
long stackSize();
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
	for(int i=0;i<prev.size();++i) if(i!=index) ofs<<prev(i)<<'\n';
	ofs.flush();
	ofs.close();
	return removed;
}
void show(int index) {
	cout<<get(index)<<'\n';
}
long stackSize() {
	return count(istreambuf_iterator<char>(ifstream(getFile())),istreambuf_iterator<char>(),'\n');
}
