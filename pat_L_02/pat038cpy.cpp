#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 1000010

int wage[MAXN];
int N, M;
void build(int, int);
void swap(int *, int *);

int main(void){
	cin >> N >> M;

	for(int i = 1; i <= N; ++i){
		cin >> wage[i];
	}

	for(int i = N/2; i >= 1; --i){
		build(i, N);
	}

	int a = N > M ? M : N;
	int c = N;
	for(int i = a; i > 0; --i){
		swap(&wage[1], &wage[c]);
		build(1,--c);
	}

	cout << wage[N];
	c = N - 1;
	while(--a){
		cout << " " <<wage[c];
		--c;
	}
	cout << endl;
	return 0;
}

void build(int left, int right){
	int tmp, i, j;
	tmp = wage[left];
	i = left;
	j = 2 * i;
	while(j <= right){
		if(j < right && wage[j] < wage[j + 1])
			++j;
		if(wage[j] > tmp){
			wage[i] = wage[j];
			i = j;
			j *= 2;
		}else
			break;
	}

	wage[i] = tmp;
}

void swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
