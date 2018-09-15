#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<algorithm>
using namespace std;
int days[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
int yearday[2]={365,366};
int decide(int year){
    if(year%4!=0||(year%100==0&&year%400!=0))
		return 0;
	return 1;
}
int frontday(int year,int month,int day){
	int sum=0;
	for(int i=1;i<month;i++)
		sum+=days[decide(year)][i];
	return sum+day;
}
int backday(int year,int month,int day){
	int sum=0;
	for(int i=month+1;i<=12;i++){
		sum+=days[decide(year)][i];
	}
	return sum+days[decide(year)][month]-day;
}
int judgemonthday(int year,int month1,int day1,int month2,int day2){
	int sum=0;
	int r=decide(year);
	if(month1==month2) return day2-day1;
	for(int i=month1;i<month2;i++){
	  sum+=days[r][i];  
	}
	return sum-day1+day2;
}

int main(){	
	int startYear,startMonth,startDay;
	int endYear,endMonth,endDay;
	int sum=0;
	scanf("%d%d%d",&startYear,&startMonth,&startDay);
	scanf("%d%d%d",&endYear,&endMonth,&endDay);
	if(startYear==endYear)
		sum=judgemonthday(startYear,startMonth,startDay,endMonth,endDay);
	if(endYear-startYear==1)
		sum=backday(startYear,startMonth,startDay)+frontday(endYear,endMonth,endDay);
	if(endYear-startYear>1){
	    sum=backday(startYear,startMonth,startDay)+frontday(endYear,endMonth,endDay);
		for(int i=startYear+1;i<endYear;i++)
			sum+=yearday[decide(i)];
	}
	printf("%d\n",sum);
	return 0;
}
