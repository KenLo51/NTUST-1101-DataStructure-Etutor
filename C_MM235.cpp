#include <stdio.h>
#include <stdlib.h>
int main(){
	scanf("%d", &n);
	printf("%d\n", (n>0? factorial(n)/n:0));
	return 0;
}
