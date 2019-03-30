#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	double x, y = 0.0;
	scanf("%lf", &x);

	if(x <= 15.0){
		y = 4.0 * x / 3.0;
	}else{
		y = 2.5 * x - 17.5;
	}
	printf("%.2lf\n", y);
	return 0;
}
