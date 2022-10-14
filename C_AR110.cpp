#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int main(){
	int times;
	scanf("%d", &times);
	for(int t=0; t<times; t++){
		vector<int> den;
		int total_num;
		int money;
		while(1){//read
			int i;
			scanf("%d", &i);
			den.push_back(i);
			if(i==1) break;
		}
		scanf("%d", &money);
		//solve
		int nums[money+1][2];//init, [[numbers_of_coin, coin_value_of_the_last]]
		for(int i=0;i<=money;i++){
			nums[i][0] = 0;
			nums[i][1] = -1;
		}
		nums[0][1] = 0;
		//solve
		for(int i=den.size()-1; i>=0; i--){
			for(int put_ptr=0; put_ptr<=money; put_ptr++){
				if( (put_ptr + den[i])>money ) break;
				int this_num = nums[put_ptr][0];
				int next_num = nums[put_ptr + den[i]][0];
				if( (this_num+1 < next_num) || (nums[put_ptr+den[i]][1] == -1)){
					nums[put_ptr + den[i]][0] = nums[put_ptr][0] + 1;
					nums[put_ptr + den[i]][1] = den[i];
				}
			}
		}
		total_num = nums[money][0];//get number of total coins
		vector<int> num;//get number of each coin
		int num_ptr=money;
		for(int i=0; i<den.size(); i++){
			num.push_back(0);
			while(nums[num_ptr][1] == den[i]){
				num[ num.size()-1 ] += 1;
				num_ptr = num_ptr - den[i];
				if(den[i]<=0) break;
			}
			if(den[i]<=0) break;
		}
		//print the result
		printf("%d\n", total_num);
		for(int i=0;i<den.size();i++)	printf("%d %d\n", den[i], num[i]);
	}
	return 0;
}
