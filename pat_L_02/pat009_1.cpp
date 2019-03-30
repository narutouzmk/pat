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

int dis[MAXS];
int pay[MAXS];
int N, M, S, D;

void Dijkstra(int);
void createP();

int main(void){
	cin >> N >> M >> S >> D;
	
	createP();

	Dijkstra(S);

	if(dis[D] < INF){
		cout << dis[D] << " " << pay[D] << endl;
	}

	return 0;
}

void createP(){
	int a, b, c, d, i, j;
	
	for(i = 0; i < N; ++i){
		dis[i] = INF;
		pay[i] = INF;
		visit[i] = 0;
	}

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

	for(i = 0; i < N; ++i){
		dis[i] = road[S][i].r_long;
		pay[i] = road[S][i].r_weight;
	}
}


void Dijkstra(int s){
	int i, j, k;
	int min, cost = 0;

	visit[s] = 1;

	for(i = 0; i < N; ++i){
		min = INF;
		for(j = 0; j < N; ++j){
			if(!visit[j] && dis[j] < min){
				min = dis[j];
				k = j;
				cost = pay[j];
			}
		}
		visit[k] = 1;

		for(j = 0; j < N; ++j){
			if(!visit[j] && dis[j] > min + road[k][j].r_long){
				dis[j] = min + road[k][j].r_long;
				pay[j] = cost + road[k][j].r_weight;
			}else if(!visit[j] && dis[j] == min + road[k][j].r_long && cost + road[k][j].r_weight < pay[j]){
				pay[j] = cost + road[k][j].r_weight;
			}
		}
	}

}












