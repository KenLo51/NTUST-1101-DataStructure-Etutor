#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;
int main(){
	vector<int> pos(2, 0);
	int total_distance=0;
	for(int i=0;i<5;i++){
		vector<int> next(2, 0);
		scanf("%d %d", &(next[0]), &(next[1]));
		total_distance += abs(next[0]-pos[0]) + abs(next[1]-pos[1]);
		pos = next;
	}
	printf("%d\n",total_distance);
	return 0;
}
