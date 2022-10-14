#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
int main(){
	int times;
	scanf(" %d", &times);
	for(int t=0; t<times; t++){
		int a, b;
		scanf(" %d %d", &a, &b);
		
		int i;
		for(i=min(a,b); i>1; i--)
			if( (a%i == 0) && (b%i == 0) ) break;
		printf("%d ", i);
		for(i=max(a,b);  i<a*b; i++)
			if( (i%a == 0) && (i%b == 0) ) break;
		printf("%d\n", i);
	}
	return 0;
}
