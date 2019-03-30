#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int age, time;
	double wage = 0.0;

	scanf("%d %d", &age, &time);

	if(age >= 5){
		wage = time > 40 ? 40 * 50.0 + (time - 40) * 50.0 * 1.5 : time * 50;
	}else{
		wage = time > 40 ? 40 * 30.0 + (time - 40) * 30.0 * 1.5 : time * 30;
	}

	printf("%.2lf\n", wage);
	return 0;
}
