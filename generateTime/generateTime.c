#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int check_lap_year(int year){
	if((year%4 == 0 && year%100 != 0) || (year%400 == 0)) return 1;
	return 0;
}

void convert(int hour, int minute, int second){
	if(second >= 60){
		second = 0;
		minute++;
		if(minute >= 60){
			minute = 0;
			hour++;
			if(hour >= 24) hour = 0;
		}
	}
	printf("Time: %2d:%02d:%02d",hour,minute,second);
}

void generate_time(){
	//random month in (day,month,year) 
	int day,month,year;
	srand(time(NULL));
	month = rand()%12 + 1; // 1 <= month <= 12
		
	//random day with each month
	srand(time(NULL));
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			day = rand()%31 + 1; // 1 <= day <= 31
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day = rand()%30 + 1; // 1 <= day <= 30
			break;
		case 2:
			day = rand()%29 + 1; // 1 <= day <= 29
			break;
	}
	
	//random year with day - d from start to end
	srand(time(NULL));
	int start = 2023;
	int end = 2031;
	year = rand()%(end - start + 1) + start;
		//check lap year if month == 2 && day == 29
	if(month == 2 && day == 29) while(check_lap_year(year) != 1) year = rand()%end + (start - end + 1);
	
	//random (hour,minute,second) 
	srand(time(NULL));
	int hour = rand()%24; // 0 <= hour <= 23
	int minute = rand()%61; // 0 <= minute <= 60
	int second = rand()%61; // 0 <= second <= 60
	printf("Day: %02d/%02d/%d\n",day,month,year);
	convert(hour,minute,second);
}

int main(){
	generate_time();
	return 0;
}
