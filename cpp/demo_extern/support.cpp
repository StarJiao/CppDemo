#include <iostream>

using namespace std;

extern int count;
void write_extern(int num){
	cout<< "count is : " << count << endl;
	cout<< "transport num is : " << num << endl;
}
