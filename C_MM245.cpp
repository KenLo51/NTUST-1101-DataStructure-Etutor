#include <stdio.h>
#include <stdlib.h>
bool isPrime(int num){
	for(int i=2;i<num;i++)
		if((num%i)==0) return 0;
	return 1;
}
int main(){
	int num, total_prime=0;
	scanf("%d", &num);
	for(int i=2;i<=num;i++){
		if(isPrime(i)){
			printf("%s%d", (i==2? "":" "), i);
			total_prime++;
		}
	}
	printf("\n%d\n", total_prime);
	return 0;
}
