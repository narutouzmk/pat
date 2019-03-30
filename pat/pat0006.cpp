#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct Node{
	int Date;
	struct Node *Next;
}Node;

typedef struct Node *PtrToNode;
typedef PtrToNode List;

int factorialSum(List L);

int main(){
	int N, i;
	List L, p;
	L = NULL;
	p = NULL;
	scanf("%d", &N);
	for(i = 0; i < N; ++i){
		p = (List)malloc(sizeof(Node));
		scanf("%d", &p->Date);
		p -> Next = L;
		L = p;
	}

	printf("%d\n", factorialSum(L));

	return 0;
}

int factorialSum(List L){
	int i, n;
	int count, result = 0;
	List p = NULL;
	p = L;
	while(p != NULL){
		count = 1;
		n = p -> Date;
		for(i = n; i > 0; --i){
			count *= i;
		}
		result += count;
		p = p -> Next;
	}

	return result;
}
