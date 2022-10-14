/*
問題描述 ：

俗話說：「三天打魚兩天曬網」表示一個人沒有恆心。小明就是這句俗話的最佳代表。他從 2007 年 1 月 1 日 ( 星期一 ) 起，就開始三天打魚兩天曬漁網，遇到週日更是偷懶的跑出去玩。現在你在某一天要去找小明，你要知道那天小明事要做什麼事情才能如願的找到他。

輸入說明 ：

依序輸入年、月、日，之間以空白隔開。此日期大於 2007 年 1 月 1 日。

輸出說明 ：

輸出在那天小明是在作什麼事情。

打魚 => He isfishing at day

曬網 => He is sleepingat day

跑出去玩 => He is playing at day
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){	
	struct tm tm_in = {0};
	scanf("%d %d %d", &(tm_in.tm_year), &(tm_in.tm_mon), &(tm_in.tm_mday));
	tm_in.tm_year -= 1900;
	tm_in.tm_mon -= 1;
	
	//if sunday
	time_t time_temp = mktime(&tm_in);
	struct tm *tm_info = gmtime(&time_temp);
	if(tm_info->tm_wday == 6){
		printf("He is playing at day\n");
		return 0;
	}
	
	//count days
	struct tm tm0 = {0};
	sscanf("2007/1/1", "%d/%d/%d", &(tm0.tm_year), &(tm0.tm_mon), &(tm0.tm_mday));
	tm0.tm_year -= 1900;
	tm0.tm_mon -= 1;
	
	time_t diff_day = (mktime(&tm_in) - mktime(&tm0))/(60*60*24);
	diff_day -= diff_day/7;
	switch(diff_day%5){
		case 0:
		case 1:
		case 2:
			printf("He is fishing at day\n");
			break;
		case 3:
		case 4:
			printf("He is sleeping at day\n");
			break;
	}
	return 0;
}
