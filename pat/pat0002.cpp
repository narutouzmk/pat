#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 10

using namespace std;

double fun(int n, double a[], double x);

int main(){
	int n, i;
	double a[MAXN], x;

	scanf("%d %lf", &n, &x);

	for(i = 0; i <= n; ++i)
		scanf("%lf", &a[i]);
	printf("%.1f\n", fun(n, a, x));
	return 0;
}

double fun(int n, double a[], double x){
	int i;
	double result = 0.0, coe = 1.0;
	for(i = 0; i <= n; ++i){
		result += a[i] * coe;
		coe *= x;
	}
	return result;
}
