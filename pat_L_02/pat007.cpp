#include <iostream>
#include <cstring>
#include <iomanip>//cout << setprecision(2) << a<<endl;
#include <cstring>

using namespace std;

/*以下是深搜，内存溢出*/
#define MAXS 10005
#define INF 32766
int visit[MAXS] = {0};
int S[MAXS][MAXS] = {0};
int N, M, count = 0, road_long = 0;
int people[MAXS] = {0};

void dfs(int);

int main(void){
	int a, b, i, j;
	int people[MAXS] = {0};
	
	for(i = 0; i < MAXS; ++i){
		for(j = 0; j < MAXS; ++j){
			S[i][j] = INF;
		}
	}

	cin >> N >> M;
	
	for(i = 0; i < M; ++i){
		cin >> a >> b;
		if(!people[a]){
			people[a] = a;
		}
		if(!people[b]){
			people[b] = b;
		}
		S[a][b] = S[b][a] = 1;
	}
	
	for(i = 0; i < MAXS; ++i){
		if(people[i] != 0){
			double a = 0.0;
			dfs(people[i]);
			a = count;
			for(j = 0; j < MAXS; ++j)
				visit[j] = 0;
			cout << people[i] <<": "<< setiosflags(ios::fixed) << setprecision(2) << (a / N) * 100.0 << "%" << endl;
			count = 0;
			road_long = 0;
		}
	}

	return 0;
}

void dfs(int cur){
	if(visit[cur] == 1 || road_long > 6){
		return;
	}
	
	++count;
	visit[cur] = 1;

	for(int i = 0; i <= N; ++i){
		if(!visit[i] && S[cur][i] < INF && road_long < 6){
			++road_long;
			dfs(i);
			--road_long;
		}
	}
}
