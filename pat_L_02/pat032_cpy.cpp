#include <iostream>
#include <cstdio>

using namespace std;

/*并查集判断连通性*/

#define MAXN 1005


int vis[MAXN] = {0};
int cnt[MAXN] = {0};

int N, M;

int getRoot(int a){
	if(vis[a] == a)
		return vis[a];
	vis[a] = getRoot(vis[a]);
	return vis[a];
}

void merge(int a, int b){
	int x = getRoot(a);
	int y = getRoot(b);

	if(x != y){
		vis[x] = y;
	}
}

int main(void){
	int a, b;
	int count = 0, flag = 1;
//	cin >> N >> M;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; ++i){
		vis[i] = i;
	}

	for(int i = 0; i < M; ++i){
		scanf("%d %d", &a, &b);
		cnt[a]++;
		cnt[b]++;
		merge(a, b);
	}

	for(int i = 1; i <= N; ++i){
		if(vis[i] == i){
			++count;
		}
	}

	if(count == 1){
		for(int i = 1; i <= N; ++i){
			if(cnt[i] % 2 == 1){
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("1\n");
		else
			printf("0\n");
	}else
		printf("0\n");
	return 0;
}
