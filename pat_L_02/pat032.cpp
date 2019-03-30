#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 1005
#define MAX 0x3f3f3f3f
//#define MIN 0xc0c0c0c0

int vis[MAXN] = {0};
int cnt[MAXN] = {0};
int map[MAXN][MAXN];
int N, M;

void dfs(int cur);

int main(void){
	int a, b;
	int flag = 1;;
	scanf("%d %d", &N, &M);

	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= N; ++j){
			map[i][j] = 0;
		}
	}

	for(int i = 0; i < M; ++i){
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
		cnt[a]++;
		cnt[b]++;
	}

	dfs(1);

	for(int i = 1; i <= N; ++i){
		if(vis[i] == 0 || cnt[i] % 2 == 1){
			flag = 0;
			break;
		}
	}

	printf("%d\n", flag);
	return 0;
}
/*并查集判断连通性*/

/*dfs判断连通性*/
void dfs(int cur){
	int i;
	if(vis[cur]){
		return;
	}

	vis[cur] = 1;

	for(i = 1; i <= N; ++i){
		if(!vis[i] && map[cur][i]){
			dfs(i);
		}
	}
}
