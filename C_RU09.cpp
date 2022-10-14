#include <stdio.h>
#include <stdlib.h>
int main(){
	size_t amount;
	scanf(" %d", &amount);
	int nums[amount];
	for(int i=0; i<amount; i++){
		scanf(" %d", nums+i);
	}
	
	
	for(int i=0; i<amount; i++){
		printf("%d,", nums[i]);
	}printf("\n");
	return 0;
}
