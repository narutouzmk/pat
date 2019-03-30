#include <iostream>
#include <cstdio>
#include <cstdlib>

//#define CON 0.3048

using namespace std;

int main(){
	int foot, inch, cm;
	double m;
	scanf("%d", &cm);
	foot = cm / 30.48;

	m = cm / 30.48 - foot;
	inch = m * 12;

	printf("%d %d\n", foot, inch);
	return 0;

}

/*int main(){
	int cm;
	double foot, inch;
	double tmp;
	scanf("%d", &cm);
	inch = cm / (30.48*(12.0 + 1.0/12.0));
	foot = inch * 12;

	printf("%lf %lf", foot, inch);
	return 0;
}*/
