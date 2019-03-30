#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f
/*Prim*/

int mp[105][105];
int vis[105], dis[105];
int N;

void Prim(int);

int main(void){
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= N; ++j){
			mp[i][j] = INF;
		}
	}

	for(int i = 0; i < N * (N - 1) / 2; ++i){
		int a, b, c, s;
		scanf("%d %d %d %d", &a, &b, &c, &s);
		if(s){
			mp[a][b] = 0;
			mp[b][a] = 0;
		}else{
			mp[a][b] = c;
			mp[b][a] = c;
		}
	}

	Prim(1);
	return 0;
}

void Prim(int s){
	int i, j, k, min;
	int sum = 0;
	memset(vis, 0, sizeof(vis));

	for(int i = 1; i <= N; ++i){
		dis[i] = mp[s][i];
	}

	vis[s] = 1;
	dis[s] = 0;

	for(int i = 1; i < N; ++i){
		min  = INF;
		k = -1;
		for(int j = 1; j <= N; ++j){
			if(!vis[j] && dis[j] < min){
				k = j;
				min = dis[j];
			}
		}
		if(k == -1){
			break;
		}
		vis[k] = 1;
		sum += dis[k];
		for(int j = 1; j <= N; ++j){
			if(!vis[j] && dis[j] > mp[k][j]){
				dis[j] = mp[k][j];
			}
		}
	}

	printf("%d\n", sum);
	return;
}
