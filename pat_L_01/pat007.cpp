#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int time, minute;
	char c;
	scanf("%d%c%d", &time, &c, &minute);
	if(time > 12){
		printf("%d%c%d PM\n", time%12, c, minute);
	}else if(time == 12){
		printf("%d%c%d PM\n", time, c, minute);
	}else{
		printf("%d%c%d AM\n", time, c, minute);
	}
	return 0;
}
