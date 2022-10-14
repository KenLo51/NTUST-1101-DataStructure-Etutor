#include <stdio.h>
#include <stdlib.h>
int Pascal(int row, int index){
	if((index<=0)||(index>=row))return 1;
	return Pascal(row-1,index-1)+Pascal(row-1,index);
}
int main(){
	int times;
	scanf("%d", &times);
	for(int t=0; t<times; t++){
		int row, index;
		scanf("%d %d", &row, &index);
		printf("%d\n", Pascal(row, index));
	}
	return 0;
}
