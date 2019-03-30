#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	double threshold, pi = 1.0f;
	int i = 1;
	double f1, f2;
	scanf("%lf", &threshold);
	f1 = 1.0;
	f2 = 1.0;
	while(f1/f2 >= threshold){
		//pi += f1 / f2;
		f1 *= i;
		f2 *= 2.0 * i + 1.0;
		pi += f1 / f2;
		++i;
	}

	printf("%6lf\n", pi * 2.0);
	return 0;
}
