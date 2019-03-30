#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAXS 101

struct Fraction{
	int a;
	int b;
};

typedef struct Fraction Fraction;

int gcd(int, int);
int lcm(int, int);
/*int getFZ(Fraction *, int, int);
int getFM(Fraction *, int);*/
Fraction *getResult(Fraction fraction[], int n);
int main(void){
	int N;
	int fz, fm, coe;
	scanf("%d", &N);
	getchar();

	Fraction fraction[MAXS];
	Fraction *result;

	for(int i = 0; i < N; ++i){
		scanf("%d/%d", &fraction[i].a, &fraction[i].b);
		getchar();
	}

	result = getResult(fraction, N);

	result -> b = result -> b * N;
	coe = gcd(result -> a, result -> b);
	result -> a = result -> a / coe;
	result -> b = result -> b / coe;
	/*fm = getFM(fraction, N);
	fz = getFZ(fraction, N, fm);

	fm *= N;
	coe = gcd(fz, fm);
	
	fz /= coe;
	fm /= coe;*/

	if(result -> b == 1){
		printf("%d\n", result -> a);
	}else{
		printf("%d/%d\n", result -> a, result -> b);
	}
	return 0;
}

Fraction *getResult(Fraction fraction[], int n){
	int fz, fm, nfz;
	int coe, k;
	Fraction *F = (Fraction *)malloc(sizeof(struct Fraction));
	fz = fraction[0].a;
	fm = fraction[0].b;
	for(int i = 1; i < n; ++i){
		k = lcm(fm, fraction[i].b);
		fz = fz * (k / fm);
		fraction[i].a = fraction[i].a * (k / fraction[i].b);
		nfz = fz + fraction[i].a;
		coe = gcd(nfz, k);

		fz = nfz / coe;
		fm = k / coe;
	}

	F -> a = fz;
	F -> b = fm;
	return F;

}

/*int getFM(Fraction fraction[], int n){
	int i, k;
	int count;
	k = fraction[0].b;
	for(i = 1; i < n; ++i){
		k = lcm(k, fraction[i].b);
	}
	return k;
}

int getFZ(Fraction fraction[], int n, int fm){
	int i, k, sum = 0;
	for(i = 0; i < n; ++i){
		fraction[i].a = fraction[i].a * (fm / fraction[i]);
	}

	for(i = 0; i < n; ++i){
		sum += fraction[i].a;
	}
	return sum;
}*/

int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b){
	return a / gcd(a, b) * b;
}
