#include <stdio.h>
int rec(int num){
	if(num<=0) return 1;
	int sum=0;
	for(int i=0; i<num; i++)
		sum += rec(i)*rec(num-i-1); 
	return sum;
}
int main(){
	int num;
	scanf("%d", &num);
	printf("f(%d)=%d\n", num, rec(num));
	return 0;
}
