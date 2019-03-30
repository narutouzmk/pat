#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 10005
#define MAX 0x3f3f3f3f

int edge[MAXN][MAXN];
int A[MAXN][MAXN], path[MAXN][MAXN];
int num[105] = {0};
int N, M, K;

void flyod();
int main(void){
	int from, to, n;

	cin >> N >> M;
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= N; ++j){
			edge[i][j] = MAX;
		}
	}

	for(int i = 0; i < M; ++i){
		cin >> from >> to;
		edge[from][to] = 1;
		edge[to][from] = 1;
	}

	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> num[i];
	}

	flyod();

	for(int i = 0; i < n; ++i){
		double sum = 0.0;
		int p = num[i];
		for(int j = 1; j <= N; ++j){
			if(j != p){
				sum += A[p][j];
			}
		}

		printf("Cc");
		printf("(%d)=%.2lf\n", num[i], (N - 1) / sum);
	}

	return 0;
}

void flyod(){
	int i, j, k;

	for(i = 1; i <= N; ++i){
		for(j = 1; j <= N; ++j){
			A[i][j] = edge[i][j];
			path[i][j] = -1;
		}
	}

	for(k = 1; k <= N; ++k){
		for(i = 1; i <= N; ++i){
			for(j = 1; j <= N; ++j){
				if(A[i][j] > A[i][k] + A[k][j]){
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}
