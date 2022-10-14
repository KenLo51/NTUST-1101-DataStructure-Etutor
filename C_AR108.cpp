#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;
int main(){
	string v;
	cin>>v;
	for(char c='a'; c<='z'; c++){
		int num = count(v.begin(), v.end(), c) + count(v.begin(), v.end(), c-('a'-'A'));
		if(num>0) printf("%c %d\n", c, num);
	}
	return 0;
}
