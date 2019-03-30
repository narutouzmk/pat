#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void){
	int num, n, sign = 1;
	int stack[100] = {0}, top = -1;

	scanf("%d", &num);

	if(num == 0){
		printf("ling\n");
		return 0;
	}
	sign = num > 0 ? 1 : -1;
	if(sign == -1){
		num = -num;
		printf("fu ");
	}
	while(num > 0){
		n = num % 10;
		stack[++top] = n;
		num /= 10;
	}
	
	while(top > 0){
		switch(stack[top]){
			case 0:
				printf("ling ");
				break;
			case 1:
				printf("yi ");
				break;
			
			case 2:
				printf("er ");
				break;
			case 3:
				printf("san ");
				break;
			
			case 4:
				printf("si ");
				break;
			case 5:
				printf("wu ");
				break;
			
			case 6:
				printf("liu ");
				break;
			case 7:
				printf("qi ");
				break;
			
			case 8:
				printf("ba ");
				break;

			case 9:
				printf("jiu ");
				break;
		}

		--top;
	}

		switch(stack[top]){
			case 0:
				printf("ling");
				break;
			case 1:
				printf("yi");
				break;
			
			case 2:
				printf("er");
				break;
			case 3:
				printf("san");
				break;
			
			case 4:
				printf("si");
				break;
			case 5:
				printf("wu");
				break;
			
			case 6:
				printf("liu");
				break;
			case 7:
				printf("qi");
				break;
			
			case 8:
				printf("ba");
				break;

			case 9:
				printf("jiu");
				break;
		}
	printf("\n");
	return 0;

}
