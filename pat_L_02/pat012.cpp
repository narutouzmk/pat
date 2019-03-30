#include <iostream>

using namespace std;

#define MAXS 100000

int num[MAXS];
int N;


void heap_sort(int *);
void build_heap(int *, int, int);

int main(void){
	cin >> N;

	for(int i = 1; i <= N; ++i){
		cin >> num[i];
	}

	heap_sort(num);

	for(int i = 1; i < N; ++i){
		cout << num[i] << " ";
	}

	cout<< num[N] <<endl;
}

void heap_sort(int *A){
	int i, tmp;
	
	for(i = N/2; i >= 1; --i){
		build_heap(A, i, N);
	}

	for(i = N; i >= 2; --i){
		tmp = A[1];
		A[1] = A[i];
		A[i] = tmp;
		build_heap(A, 1, i - 1);
	}
}

void build_heap(int *A, int left, int right){
	int tmp, i, j;
	tmp = A[left];
	i = left;
	j = left * 2;

	while(j <= right){
		if(j < right && A[j] < A[j + 1]){
			++j;
		}

		if(tmp < A[j]){
			A[i] = A[j];
			i = j;
			j = j * 2;
		}else{
			break;
		}
	}

	A[i] = tmp;
}
