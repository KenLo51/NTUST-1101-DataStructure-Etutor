#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a>b? a:b)
#define min(a,b) (a<b? a:b)
void swap(int *a, int*b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void buildMinHeap(int *arr, size_t size, size_t index){
	if( index*2 > (size) ) return;
	
	int left_index  = index*2;
	int right_index = (index*2+1>size)? left_index:index*2+1;
	if( min(arr[left_index-1], arr[right_index-1]) < arr[index-1]){
		int swap_index = (arr[left_index-1]<arr[right_index-1])? left_index:right_index;
		swap( &(arr[index-1]), &(arr[swap_index-1]) );
		
		for(int i=0; i<size; i++){
			printf("%d,", arr[i]);
		}printf("swap_index(%d,%d)\n", swap_index, index);
		
		buildMinHeap(arr, size, swap_index);
	}
	return;
}
int main(){
	size_t amount;
	scanf(" %d", &amount);
	int nums[amount];
	for(int i=0; i<amount; i++){
		scanf(" %ud", nums+i);
	}
	
	for(int i=amount; i>0; i--){
		buildMinHeap(nums, amount, i);
	}
	
	for(int i=0; i<amount; i++){
		printf("%d,", nums[i]);
	}printf("\n");
	return 0;
}
