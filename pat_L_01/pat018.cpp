#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

#define THR 0.00000001

using namespace std;

double a, b, c, d;
double fun(double);

int main(){
	double low, high;
	double mid;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	scanf("%lf %lf", &low, &high);
	do{
		mid = (low + high) / 2.0;
		if(fun(mid) == 0 || (high - low) < THR){
			printf("%.2lf\n", mid);
			break;
		}else if(fun(mid) * fun(low) > 0){
			low = mid;
		}else{
			high = mid;
		}
	}while(fun(low) * fun(high) <= 0);

	return 0;
}

double fun(double set){
	return a * pow(set, 3.0) + b * pow(set, 2.0) + c * set + d;
}
