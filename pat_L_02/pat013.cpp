#include <iostream>
#include <cstring>

using namespace std;

#define MAXS 100000

int age[MAXS];
int assist[MAXS];

int N;

void qsort(int *, int, int);
void heap_sort(int *);
void merge_sort(int *, int, int);
void build_heap(int *, int, int);

int partion(int *, int, int);
void merge(int *, int, int, int);
int main(void){
	int count = 1, i;
	cin >> N;

	memset(age, 0, sizeof(age));
	memset(assist, 0, sizeof(assist));

	for(i = 1; i <= N; ++i){
		cin >> age[i];
//		cout << age[i] << " ";//test;
	}

//	cout << endl;//test
//	qsort(age, 1, N);
	heap_sort(age);
//	merge_sort(age, 1, N);

	for(i = 2; i <= N; ++i){
//		cout << age[i] << " ";//test
		if(age[i] != age[i - 1]){
			cout << age[i - 1] << ":" << count << endl;;
			count = 1;
		}else{
			++count;
		}
	}

//	cout << endl;//test

	cout << age[i-1] << ":" << count << endl;
	return 0;
}

void heap_sort(int *A){
	int i, j, k;

	for(i = N/2; i >= 1; --i){
		build_heap(A, i, N);
	}

	for(i = N; i > 1; --i){
		k = A[i];
		A[i] = A[1];
		A[1] = k;
		build_heap(A, 1, i - 1);
	}
}

void build_heap(int *A, int left, int right){
	int i, j, tmp;
	i = left;
	j = left * 2;
	tmp = A[left];

	while(j <= right){
		if(j < right && A[j] < A[j+1]){
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

void merge_sort(int *A, int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		merge_sort(A, left, mid);
		merge_sort(A, mid + 1, right);
		merge(A, left, mid, right);
	}
}

void merge(int *A, int left, int mid, int right){
	int i, j, k;
	for(i = left; i <= right; ++i){
		assist[i] = A[i];
	}

	k = left;

	for(i = left, j = mid + 1; i <= mid && j <= right;){
		if(assist[i] > assist[j]){
			A[k] = assist[j];
			++k;
			++j;
		}else{
			A[k] = assist[i];
			++k;
			++i;
		}
	}

	while(i <= mid){
		A[k] = assist[i];
		++k;
		++i;
	}

	while(j <= right){
		A[k] = assist[j];
		++k;
		++j;
	}
}

void qsort(int *A, int left, int right){
	if(left < right){
		int i, j, k;
		k = partion(A, left, right);
		qsort(A, left, k - 1);
		qsort(A, k + 1, right);
	}
}

int partion(int *A, int left, int right){
	int  i, j, k;
	int tmp;
	tmp = A[left];
	i = left;
	j = right;
	while(i < j){
		while( i < j && tmp < A[j]) --j;
		if(i < j){
			A[i] = A[j];
			++i;
		}
		while(i < j && tmp > A[i]) ++i;
		if(i < j){
			A[j] = A[i];
			j--;
		}
	}
	A[i] = tmp;
	return i;
}
