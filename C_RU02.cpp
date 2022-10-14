#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int move_n=0;
void print_Hanoi(char *str, vector<int> *towers){
	printf("***********************************\n");
	printf("%s", str);
	printf("\nA%: ");
	for(int i=0; i<towers[0].size(); i++) printf("%s%d", (i>0? " ":""), towers[0][i]);
	printf("\nB%: ");
	for(int i=0; i<towers[1].size(); i++) printf("%s%d", (i>0? " ":""), towers[1][i]);
	printf("\nC%: ");
	for(int i=0; i<towers[2].size(); i++) printf("%s%d", (i>0? " ":""), towers[2][i]);
	printf("\n");
}
void Hanoi_rec_print(int move_n, vector<int> *towers){
	char print_str[80];
	if(towers[0].size()==0 && towers[1].size()==0){
		sprintf(print_str, "Total Moved %d Times:", move_n);
		print_Hanoi(print_str, towers);
		return;
	}
	if(move_n%5 == 0){
		sprintf(print_str, "After Moved %d Times:", move_n);
		print_Hanoi(print_str, towers);
		return;
	}
}
void Hanoi_rec(int n, vector<int> &A, vector<int> &B, vector<int> &C, vector<int> *towers){
	if(n<=1){
		C.push_back( A[A.size()-1] );
		A.pop_back();
		move_n++;
		Hanoi_rec_print(move_n, towers);
		return;
	}
	Hanoi_rec(n-1, A, C, B, towers);
	
	C.push_back( A[A.size()-1] );
	A.pop_back();
	move_n++;
	Hanoi_rec_print(move_n, towers);
	Hanoi_rec(n-1, B, A, C, towers);
	return;
}
int main(){
	int discs=0;
	scanf("%d", &discs);
	vector<int> towers[3];
	for(int i=0; i<discs; i++)
		towers[0].push_back(discs-i);
	printf("Number of Discs: %d\n", discs);
	print_Hanoi("Initial State:", towers);
	Hanoi_rec(discs, towers[0], towers[1], towers[2], towers);
	return 0;
}
