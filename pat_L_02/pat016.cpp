#include <iostream>
#include <cstdio>

using namespace std;

#define MAXS 1001

int fun[MAXS] = {0};
int d_fun[MAXS] = {0};

int main(void){
	int coe, ex, i;
	while(scanf("%d %d", &coe, &ex) != EOF){
//		cout << "coe=" <<coe <<",ex="<< ex <<endl;
		fun[ex] = coe;
	}

	for(int i = 1; i < MAXS; ++i){
		 if(fun[i] != 0){
			d_fun[i - 1] = fun[i] * i;
		 }
	}

	i = MAXS - 1;

	while(i >= 0 && d_fun[i] == 0) --i;

	if(i == -1){
		printf("0 0\n");
		return 0;
	}

	printf("%d %d", d_fun[i], i);
	--i;
	
	for(; i >= 0; --i){
		if(d_fun[i] != 0){
			printf(" %d %d", d_fun[i], i);
		}
	}

	printf("\n");
	return 0;
}
