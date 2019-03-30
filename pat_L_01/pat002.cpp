#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int time, inter;
	int h, m, c = 10;
	int hour, minute;
	scanf("%d %d", &time, &inter);
	hour = time%10000/1000*10 + time%1000/100;
	minute = time%100;
	if(inter < 0){
		h = (-inter)/60;
		m = (-inter) - h * 60;
		if(minute - m < 0){
			hour--;
			minute = minute + 60 - m;
			hour -= h;
		}else{
			hour -= h;
			minute = minute - m;
		}
	}else{
		h = inter / 60;
		m = inter - h * 60;
		hour = hour + h + (minute + m) / 60;
		minute = (minute + m) % 60;
	}
	if(minute < 10){
		printf("%d0%d\n", hour%24, minute%60);
	}else{
		printf("%d%d\n", hour%24, minute%60);
	}
	return 0;
}
