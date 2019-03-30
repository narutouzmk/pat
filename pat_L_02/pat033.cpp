#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 2019

int vis[MAXN];
int path[MAXN], count = 0;
int map[MAXN][MAXN];
int N, M, S;

void dfs(int cur);

int main(void){
	int a, b;
	cin >> N >> M >> S;

	memset(vis, 0, sizeof(vis));
	memset(path, 0, sizeof(path));
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= N; ++j){
			map[i][j] = 0;
		}
	}

	for(int i = 0; i < M; ++i){
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	dfs(S);

	int i = 0;
	cout << path[i];
	++i;
	while(path[i] != 0){
		cout << " " << path[i];
		++i;
	}
	if(count < N){
		cout << " " << 0;
	}
	cout << endl;

	return 0;
}

void dfs(int cur){
	if(vis[cur]){
		return;
	}

	int i;

	vis[cur] = 1;
	path[count++] = cur;

	for(i = 1; i <= N; ++i){
		if(!vis[i] && map[cur][i]){
			dfs(i);
			path[count++] = cur;
		}
	}
}
