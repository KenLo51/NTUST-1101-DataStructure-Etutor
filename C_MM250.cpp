#include <stdio.h>
#include <stdlib.h>
int main(){
	float capacity, consumption;
	scanf("%f %f", &capacity, &consumption);
	float hours = capacity / consumption / 60;
	printf("%.1f\n", hours);
	return 0;
}
