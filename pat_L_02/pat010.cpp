#include <iostream>
#include <cstring>

using namespace std;

#define INF 32766
#define MAXS 1002

int road[MAXS][MAXS];
int visit[MAXS];

int N, M;
int minc = 0;

void Prim();
int main(void){
	int i, j, a, b, c;
	int flag = 0;

	cin >> N >> M;

	for(i = 0; i <= N; ++i){
		for(j = 0; j <= N; ++j){
			if(i != j){
				road[i][j] = INF;
			}else{
				road[i][j] = 0;
			}
		}
	}
						
	memset(visit, 0, sizeof(visit));

	for(i = 1; i <= M; ++i){
		cin >> a >> b >> c;
		road[a][b] = c;
		road[b][a] = c;
	}

	Prim();

	for(i = 1; i <= N; ++i){
		if(!visit[i]){
			flag = 1;
		}
	}

	if(!flag){
		cout << minc <<endl;
	}else{
		cout << -1 << endl;
	}

	return 0;
}

void Prim(){
	int i, j, k, lowcost[N];
	int minP;

	for(i = 1; i <= N; ++i){
		lowcost[i] = INF;
	}
	for(i = 1; i <= N; ++i){
		lowcost[i] = road[1][i];
	}

	lowcost[1] = 0;
	visit[1] = 1;

	for(i = 1; i <= N; ++i){
		minP = INF;

		for(j = 1; j <= N; ++j){
			if(!visit[j] && lowcost[j] < minP){
				minP = lowcost[j];
				k = j;
			}
		}

		if(minP == INF){
			break;
		}
		visit[k] = 1;
		minc += minP;
		for(j = 1; j <= N; ++j){
			if(!visit[j] && lowcost[j] > road[k][j]){
				lowcost[j] = road[k][j];
			}
		}
	}
}
