#include <stdio.h>
int main(){
	int times;
	scanf("%d", &times);
	for(int t=0; t<times; t++){
		char ch;
		scanf(" %c", &ch);
		printf("%c\n", ch+2);
	}
	return 0;
}
