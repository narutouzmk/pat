#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define MAXS 500
#define INF 32766

typedef struct Road{
	int r_long;
	int r_weight;
}Road;

Road road[MAXS][MAXS];
int visit[MAXS];
int N, M, S, D;
int cur_long = 0, cur_spend = 0;
int min_long = INF, min_spend = INF;

void dfs(int);

int main(void){
	cin >> N >> M >> S >> D;
	int a, b, c, d, i, j;

	memset(visit, 0, sizeof(visit));

	for(i = 0; i < N; ++i){
		for(j = 0; j < N; ++j){
			if(i != j){
				road[i][j].r_long = INF;
				road[i][j].r_weight = INF;
			}else{
				road[i][j].r_long = 0;
				road[i][j].r_weight = 0;
			}
		}
	}
	for(i = 0; i < M; ++i){
		cin >>a >>b >>c >>d;
		road[a][b].r_long = c;
		road[a][b].r_weight = d;
		road[b][a].r_long = c;
		road[b][a].r_weight = d;
	}
	/*for(i = 0; i < N; ++i){
		for(j = 0; j < N; ++j){
		//	cout << road[i][j].r_long << " " << road[i][j].r_weight << " ";
			if(road[i][j].r_long == INF){
				printf("----");
			}else{
				printf("%4d", road[i][j].r_weight);
			}
		}
		cout << endl;
	}*/ //***********test***********//

	dfs(S);

	cout << min_long << " " << min_spend << endl;;
	return 0;
}

void dfs(int cur){
	if(cur == D){
		if(cur_long <= min_long && cur_spend <= min_spend){
			min_long = cur_long;
			min_spend = cur_spend;
//			cout<<D<<" "<<"min_long="<<min_long<<",min_spend="<<min_spend<<endl;
		}
		return;
	}

	if(visit[cur]){
		return;
	}

	int i;

//	cout << cur << " ";//test

	visit[cur] = 1;
	for(i = 0; i < N; ++i){
		if(!visit[i] && road[cur][i].r_long != INF && road[i][cur].r_weight != INF){
			cur_long += road[cur][i].r_long;
			cur_spend += road[cur][i].r_weight;
			dfs(i);
			cur_long -= road[cur][i].r_long;
			cur_spend -= road[cur][i].r_weight;
		}
	}

	visit[cur] = 0;
}
