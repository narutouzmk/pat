#include <iostream>
using namespace std;

#define MAX 0x3f3f3f3f
#define MAXN 506

int map[MAXN][MAXN];//地图
int num[MAXN];//每个城市消防队的人数
int path[MAXN];//记录最短路径，且消防队人数最多
int cnt[MAXN] = {0}, ccf[MAXN] = {0};
//到达该城市最短路径条数， 到达该城市救援队最大数量
int N, M, S, D;

void dijkstra();
void PrintRoad();

int main(void){
	int from ,to, cost;
	cin >> N >> M >> S >> D;

	for(int i = 0; i < N; ++i){
		cin >> num[i];
		ccf[i] = num[i];
		cnt[i] = 1;
	}

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(i != j)
				map[i][j] = MAX;
		}
	}

	for(int i = 0; i < M; ++i){
		cin >> from >> to >> cost;
		map[from][to] = cost;
		map[to][from] = cost;
	}

	dijkstra();
	PrintRoad();

	return 0;
}

void dijkstra(){
	int vis[N+1], dist[N+1];
	int i, j, k, min;

	for(i = 0; i < N; ++i){
		dist[i] = map[S][i];
		vis[i] = 0;
		if(map[S][i] < MAX){
			path[i] = S;
		}else{
			path[i] = -1;
		}
	}

	path[S] = -1;
	vis[S] = 1;

	for(i = 0; i < N; ++i){
		min = MAX;
		k = -1;
		for(j = 0; j < N; ++j){
			if(!vis[j] && dist[j] < min){
				min = dist[j];
				k = j;
			}
		}

		if(k == -1)
			break;

		vis[k] = 1;
		for(j = 0; j < N; ++j){
			if(!vis[j] && dist[j] > dist[k] + map[k][j]){
				dist[j] = dist[k] + map[k][j];
				path[j] = k;
				cnt[j] = cnt[k];
//				cout << "if:cnt[D]=" << cnt[D] << endl;
				ccf[j] = ccf[k] + num[j];
			}else if(!vis[j] && dist[j] == dist[k] + map[k][j]){
				cnt[j] = cnt[j] + cnt[k];//关键是记录到当前结点的路径数和判断这种方式是不是比以前叫的人多
//				cout << "else if:cnt[D]=" << cnt[D] << endl;
				if(ccf[j] < ccf[k] + num[j]){
					path[j] = k;
//					cout << "修改了cnt[D]=" << cnt[D] << endl;
					ccf[j] = ccf[k] + num[j];
				}
			}
		}
	}
}

void PrintRoad(){
	int stack[MAXN], top = -1;
	int a = D;
	stack[++top] = D;
	while(path[a] != -1){
		stack[++top] = path[a];
		a = path[a];
	}

	cout << cnt[D] << " " << num[S] + ccf[D] << endl;
	cout << stack[top];
	--top;
	while(top > -1){
		cout << " " << stack[top--];
	}

	cout << endl;
}
