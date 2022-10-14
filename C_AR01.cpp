#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector> 
#include <string>
using namespace std;
int main(){
	string str_nums;
	getline(cin, str_nums);
	while(!str_nums.empty()){
		int start = str_nums.rfind(' ')==string::npos? 0:str_nums.rfind(' ')+1;
		cout << str_nums.substr(start, str_nums.length()) << (start==0? "\n":" ");
		str_nums.erase(start<1? 0:start-1, str_nums.length());
	}
	return 0;
}
