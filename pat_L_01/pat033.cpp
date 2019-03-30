#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int gcd(int, int);
int lcm(int, int);

int main(void){
	int a1, b1;
	int a2, b2;

	int i, j, k;
	int m, n;
	
	scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);

	i = lcm(b1, b2);
	
	j = i / b1 * a1;
	k = i / b2 * a2;

	m = j + k;
	n = gcd(i, m);
	
	i /= n;
	m /= n;

	if(i == 1){
		printf("%d\n", m);
	}else{
		printf("%d/%d\n", m, i);
	}

	return 0;
}


int gcd(int a, int b){
	if(b == 0) return a;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b){
	return 
		a / gcd(a, b) * b;
}
