#include <iostream>
#include <vector>

using namespace std;
#define MAXS 500
#define INF 32766

struct E{
	int next;
	int dis;
	int cost;
};

vector<E> edge[MAXS];
int visit[MAXS];
int dis[MAXS];
int cost[MAXS];

int main(void){
	int n, m, s, d;
	int i, j;

	E temp;
	int newP;

	while(cin >>n >>m >>s >>d){
		if(n== 0 || m == 0)
			break;
		
		for(i = 0; i < n; ++i){
			edge[i].clear();
			dis[i] = INF;
			cost[i] = INF;
			visit[i] = 0;
		}

		while(m--){
			int a, b, c, d;
			cin >>a >>b >>d >>c;
			temp.next = b;
			temp.dis = d;
			temp.cost = c;
			edge[a].push_back(temp);
			temp.next = a;
			edge[b].push_back(temp);
		}

		dis[s] = 0;
		cost[s] = 0;
		visit[s] = 1;

		newP = s;

		for(i = 1; i < n; ++i){
			for(j = 0; j < edge[newP].size(); ++j){
				int next = edge[newP][j].next;
				int c = edge[newP][j].cost;
				int d = edge[newP][j].dis;

				if(visit[next]) continue;
				if(dis[next] == INF || dis[next] > dis[newP] + d || ((dis[next] == dis[newP] + d)&&(cost[next] > cost[newP] + c))){
					dis[next] = dis[newP] + d;
					cost[next] = cost[newP] + c;
				}
			}

			int min = INF;

			for(j = 0; j < n; ++j){
				if(!visit[j] && dis[j] < min){
					min = dis[j];
					newP = j;
				}
			}

			visit[newP] = 1;
		}

		cout << dis[d] << " " << cost[d] << endl;
	}
}

