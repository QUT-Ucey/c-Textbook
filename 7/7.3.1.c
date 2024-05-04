#include "stdio.h"

int year_to_day(int year,int *run_judgment)
{
	
   int a,day=0;
   a=year-1990;
   
   switch(a){
   	case 0:day=0;break;
   }
   if(a<0){
   	printf("ERROR,year need >= 1990");
   	
   }
   if(a>0&&year%4 == 0){
   	day=(year-1990)*366;
	*run_judgment=1;
	}
   	else day=(year-1990)*365;
   
   return day;
   
}

int month_to_day(int month,int *run_judgment)
{
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int totalDays = 0;
	if (*run_judgment=1){
		daysInMonth[1]=29;
	}
	for (int i = 0; i < month - 1; i++) {  
        totalDays += daysInMonth[i];  
    } 
    return totalDays;
}





int main(){
	int year,month,day,run=0;
	int *run_judgment;
	
	run_judgment=&run;
	
	scanf("%d,%d,%d",&year,&month,&day);
	/*判断年份*/
	year=year_to_day(year,run_judgment);
	/*判断月份*/
	month=month_to_day(month,run_judgment);
	
	day=year+month+day;
	
	if(day%3==0){
		printf("fishing\n");
	}
	if(day%5==0){
		printf("晒网\n");
	}
	
	printf("%d",day);
	
	
	
	return 0;
}