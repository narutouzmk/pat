#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int y, f;
	int n;
	int flag = 0;

	scanf("%d", &n);
	for(f = 0; f < 100; ++f){
		for(y = 0; y < 100; ++y){
			if(98 * f - 199 * y == n){
				flag = 1;
				printf("%d.%d\n", y, f);
				break;
			}
		}
	}

	if(flag == 0){
		printf("No Solution\n");
	}

	return 0;
}

/*
	100*f + y - n = 200 * y + 2 * f;
	=>98 * f - 199 * y = n;
	f < 100, y < 100;
	人民币只有100面额
 */
