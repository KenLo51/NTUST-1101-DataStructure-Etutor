#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
int main(){	
	int times;//read
	scanf("%d", &times);
	for(int t=0; t<times; t++){
		int end_year;
		scanf("%d", &end_year);
		
		int total=0;
		vector<int> out_years;
		for(int year=2017; year<end_year; year++){
			struct tm tm0 = {0};//set time to process
			tm0.tm_year = year - 1900;
    		tm0.tm_mon = 10 - 1;
    		tm0.tm_mday = 10;
    		time_t ret = mktime(&tm0);//fromat time
    		struct tm *tm_formated = gmtime(&ret);
    		if(tm_formated->tm_wday == 6){//check
    			out_years.push_back(year);
    			total++;
			}
		}
		printf("%d\n", total);
		for(int i=0;i<out_years.size();i++) printf("%d%s", out_years[i], ((i==out_years.size()-1)? "\n":","));
	}
	return 0;
}
