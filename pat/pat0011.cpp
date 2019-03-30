#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 10

typedef float ElementType;

ElementType Median(ElementType A[], int N);
void buildHeap(ElementType A[], int left, int right);

int main(){
	ElementType A[MAXN];
	int N, i;

	scanf("%d", &N);

	for(i = 0; i < N; ++i)
		scanf("%f", &A[i]);

	printf("%.2f\n", Median(A, N));
	return 0;
}

ElementType Median(ElementType A[], int N){
	int i;
	ElementType tmp;

	for(i = N/2 - 1; i >= 0; --i)
		buildHeap(A, i, N-1);

	for(i = N - 1; i > 0; --i){
		tmp = A[i];
		A[i] = A[0];
		A[0] = tmp;
		buildHeap(A, 0, i - 1);
	}

	return A[N/2];
}

void buildHeap(ElementType A[], int left, int right){
	int i, j;
	ElementType k;
	k = A[left];
	i = left;
	j = i * 2;
	while(j <= right){
		if(j < right && A[j] < A[j + 1]){
			++j;
		}

		if(k < A[j]){
			A[i] = A[j];
			i = j;
			j = j * 2;
		}else{
			break;
		}
	}

	A[i] = k;
}
