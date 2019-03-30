#include <iostream>

using namespace std;

#define MAXS 15
#define INF 32766

int num[MAXS][MAXS];
int visit[MAXS] = {0};
int squ[MAXS] = {0}, c = 0;;

int N, E;

void dfs(int);
void bfs(int);

int main(void){
	int a, b, i, j;
	cin >> N >> E;

	for(i = 0; i < N; ++i)
		for(j = 0; j < N; ++j)
			num[i][j] = INF;

	for(i = 0; i < E; ++i){
		cin >> a >> b;
		num[a][b] = num[b][a] = 1;
	}

	for(i = 0; i < N; ++i){
		if(!visit[i]){
			dfs(i);
			cout <<"{";
			for(j = 0; j < c; ++j){
				cout<<" "<<squ[j];
				squ[j] = 0;
			}
			cout<<" }"<<endl;
			c = 0;
		}
	}


	for(i = 0; i < N; ++i)
		visit[i] = 0;


	for(i = 0; i < N; ++i){
		if(!visit[i]){
			bfs(i);
			cout <<"{";
			for(j = 0; j < c; ++j){
				cout<<" "<<squ[j];
				squ[j] = 0;
			}
			cout<<" }"<<endl;
			c = 0;
		}
	}

	return 0;
}

void dfs(int cur){
	if(visit[cur] == 1)
		return;
	visit[cur] = 1;
	squ[c++] = cur;
	for(int i = 0; i < N; ++i){
		if(visit[i] != 1 && num[cur][i] < INF){
			dfs(i);
		}
	}
}

void bfs(int cur){
	if(visit[cur] == 1)
		return;
	int que[MAXS] = {0}, front, rear;
	front = rear = -1;
	int i, j;
	visit[cur] = 1;
	squ[c++] = cur;

	rear = (rear + 1) % MAXS;
	que[rear] = cur;

	while(front != rear){
		front = (front + 1) % MAXS;
		i = que[front];
		for(j = 0; j < N; ++j){
			if(!visit[j] && num[i][j] < INF){
				visit[j] = 1;
				squ[c++] = j;
				rear = (rear + 1) % MAXS;
				que[rear] = j;
			}
		}
	}
}
