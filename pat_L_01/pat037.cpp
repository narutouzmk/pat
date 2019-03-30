#include <iostream>

using namespace std;

int a[35];
int count = 0, N;

void dfs(int len, int sum, int next);

int main(void){
	
	cin >> N;
	for(int i = 1; i <= N/2; ++i){
		dfs(0, 0, i);
	}
	dfs(0, 0, N);

	return 0;
}

void dfs(int len, int sum, int next){
	if(sum + next > N)
		return;

	a[len++] = next;

	if(sum + next == N){
		cout << N << "=";
		for(int i = 0; i < len; ++i){
			if(i == 0){
				cout<<a[i];
			}else{
				cout<<"+"<<a[i];
			}
		}

		if(++count == 4 || next == N){
			count = 0;
			cout<<endl;
		}else{
			cout<<";";
		}
	}

	if(sum + next < N){
		sum += next;
		for(int i = next; i <= N - sum; ++i){
			dfs(len, sum, i);
		}
	}
}
