#include <iostream>
#include <stdio.h>
#include <math.h>

int IsTheNumber(const int N);

int main(){
	int n1, n2, i, cnt = 0;

	scanf("%d %d", &n1, &n2);

	for(i = n1; i <= n2; ++i){
		if(IsTheNumber(i)){
			++cnt;
		}
	}

	printf("cnt = %d\n", cnt);

	return 0;
}

int IsTheNumber(const int N){
	int i,k;
	int flag1 = 0, flag2 = 0;
	int a[10] = {0};

	int x = N;
	for(i = 1; x > 0; i += 2)
		x -= i;
	if(x == 0){
		flag1 = 1;
		k = N;

		while(k > 0){
			if(!a[i = k%10]){
				++a[i];
			}else{
				flag2 = 1;
				break;
			}
			k /= 10;
		}
	}

	return flag1 && flag2;
}
