#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
	int num, real_n;
	int stack[8] = {0}, top = -1;
	int i, j, k;
	scanf("%d", &num);

	if(num != 0){
		while(num != 0){
			stack[++top] = num%16;
			num /= 16;
		}
		while(top != -1)
			printf("%d", stack[top--]);
	}else{
		printf("0");
	}
	printf("\n");
	return 0;
}
