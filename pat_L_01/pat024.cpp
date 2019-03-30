#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int gcd(int, int);

int main(void){
	int a, b, k;
	char c;
	scanf("%d%c%d", &a, &c, &b);

	k = gcd(a, b);
	printf("%d%c%d\n", a/k, c, b/k);

	return 0;
}

int gcd(int a, int b){
	if(b == 0)
		return a;
	else{
		return gcd(b, a%b);
	}
}
