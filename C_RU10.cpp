#include <stdio.h>
#include <stdlib.h>
unsigned long long factorial(int n){
	unsigned long long result = 1;
	for(int i=2;i<=n;i++) result *= i;
	return result;
} 
int main(){
	int stair;
	scanf("%d", &stair);
	unsigned long total = 0;
	for(int num_combination=0; num_combination<(stair/2+1); num_combination++)
		total += factorial(stair-num_combination) / ( factorial(stair-2*num_combination)*factorial(num_combination) );
	printf("%d\n", total);
	return 0;
}
