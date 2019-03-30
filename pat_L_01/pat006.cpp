#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void){
	int n;
	char c;
	float f1, f2;
	scanf("%f %d %c %f", &f1, &n, &c, &f2);
	printf("%c %d %.2f %.2f\n", c, n, f1, f2);
	return 0;
}
