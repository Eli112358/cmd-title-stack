using namespace std;
int main(int argc,char *argv[]) {
	if(stackSize()>0) {
		string prev=remove(stackSize()-1);
		system("title "+prev);
	}
	return 0;
}
