#include <stdio.h>
#include <stdlib.h>
int main(){
	int times;
	scanf("%d", &times);
	for(int t=0; t<times; t++){
		int score;
		scanf("%d", &score);
		if((score-95)>=0) printf("Excellent\n");
		else if((score-85)>=0) printf("Very Good\n");
		else if((score-61)>=0) printf("Good\n");
		else printf("Careless\n");
	}
	return 0;
}
