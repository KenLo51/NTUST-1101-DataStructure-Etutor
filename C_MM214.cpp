#include <stdio.h>
#include <stdlib.h>
int main(){
	int times;
	scanf("%d", &times);
	for(int t=0;t<times;t++){
		int num_bread, num_box, boxL_Cap, boxS_Cap;
		scanf("%d %d %d %d", &num_bread, &num_box, &boxL_Cap, &boxS_Cap);
		printf("%d %d\n", (num_bread-boxS_Cap*num_box)/(boxL_Cap-boxS_Cap), (num_bread-boxL_Cap*num_box)/(boxS_Cap-boxL_Cap));
	}
	return 0;
}
