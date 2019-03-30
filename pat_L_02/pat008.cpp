#include <iostream>
#include <cstdio>
using namespace std;

#define INF 32766
#define MAXS 101

int road[MAXS][MAXS] = {0};
//int A[MAXS][MAXS] = {0};
int path[MAXS][MAXS] = {0};

int N, M;
void flyod();

int main(void){
	int i, a, b, c;
	int minA = 1, maxL = 0, minL = INF;

	cin >> N >> M;
	if(N == 1){
		cout<<0<<endl;
		return 0;
	}
	for(i = 1; i <= N; ++i){
		for(a = 1; a <= N; ++a){
			if(i == a){
				road[i][a] = 0;
			}else{
				road[i][a] = INF;
			}
			path[i][a] = -1;
		}
	}

	for(i = 1; i <= M; ++i){
		cin >> a >> b >> c;
		road[a][b] = c;
		road[b][a] = c;
	}

	
	flyod();

	for(a = 1; a <= N; ++a){
		maxL = 0;
		for(b = 1; b <= N; ++b){
			if(maxL < road[a][b]){
				maxL = road[a][b];
			}
		}

		if(maxL == INF){//无解
			cout<<0<<endl;
			return 0;
		}

		if(maxL < minL){
			minL = maxL;
			minA = a;
		}
	}
	cout << minA <<" "<< minL <<endl;
	return 0;
}

void flyod(){
	int i, j, k;
	
	for(k = 1; k<= N; ++k){
		for(i = 1; i <= N; ++i){
			for(j = 1; j <= N; ++j){
				if(road[i][k] + road[k][j] < road[i][j]){
					road[i][j] = road[i][k] + road[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}
