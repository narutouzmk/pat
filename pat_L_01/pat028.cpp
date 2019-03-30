#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAXS 1002

int can[MAXS] = {0};

int main(){
	int N, i, count, k;
	scanf("%d", &N);
	for(i = 1; i <= N; ++i)
		can[i] = i;

	i = 1;
	count = 1;
	k = N;
	while(k > 1){
		if(can[i] != 0){
			if(count % 3 == 0){
				can[i] = 0;
				count = 1;
				--k;
			}else{
				++count;
			}
		}
		i = (i + 1) % (N+1);
	}
	for(i = 1; i <= N; ++i)
		if(can[i] != 0)
			printf("%d\n", can[i]);

	return 0;
}
