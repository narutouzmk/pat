#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 1000010

long long dis[MAXN];
long long mon[MAXN];

int N, M;
void qsort(int, int, long long *);
int main(void){

	long long sum = 0;

	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%lld", &dis[i]);
	}

	getchar();
	scanf("%d", &M);
	for(int i = 1; i <= M; ++i){
		scanf("%lld", &mon[i]);
	}

	qsort(1, N, dis);
	qsort(1, M, mon);

	int i = 1, j = N;
	int x = 1, y = M;

	while(dis[i] < 0 && mon[x] < 0){
		sum += dis[i] * mon[x];
		++i;
		++x;
	}

	while(dis[j] > 0 && mon[y] > 0){
		sum += dis[j] * mon[y];
		--j;
		--y;
	}

	printf("%lld\n", sum);
	return 0;
}

void qsort(int left, int right, long long *p){
	if(left > right){
		return;
	}

	int i = left, j = right;
	int tmp = p[left];

	while(i < j){
		while(i < j && tmp < p[j]) --j;
		if(i < j){
			p[i] = p[j];
			++i;
		}
		while(i < j && tmp > p[i]) ++i;
		if(i < j){
			p[j] = p[i];
			--j;
		}
	}

	p[i] = tmp;
	qsort(left, i - 1, p);
	qsort(i + 1, right, p);
}





