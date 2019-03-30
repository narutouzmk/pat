#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

typedef struct Node *node;

void merge(node, node);

int main(void){
	int a;
	node L1 = (node)malloc(sizeof(struct Node));
	node L2 = (node)malloc(sizeof(struct Node));
	node r = NULL;
	L1 -> data = L2 -> data = -1;
	L1 -> next = NULL;
	L2 -> next = NULL;

	r = L1;
	while(scanf("%d", &a) && a != -1){
		node p = (node)malloc(sizeof(struct Node));
		p -> data = a;
		p -> next = NULL;
		r -> next = p;
		r = p;
	}

	r = L2;
	while(scanf("%d", &a) && a != -1){
		node p = (node)malloc(sizeof(struct Node));
		p -> data = a;
		p -> next = NULL;
		r -> next = p;
		r = p;
	}

	merge(L1, L2);
	return 0;
}

void merge(node L1, node L2){
	node p, q, h = NULL, r = NULL;
	node tmp = NULL;
	p = L1 -> next;
	q = L2 -> next;
	L1 -> next = NULL;
	L2 -> next = NULL;
	h = L1;
	r = h;
	free(L2);
	while(p != NULL && q != NULL){
		if(p -> data < q -> data){
			tmp = p;
			p = p -> next;
			r -> next = tmp;
			r = tmp;
			r -> next = NULL;
		}else if(p -> data == q -> data){
			tmp = p;
			p = p -> next;
			r -> next = tmp;
			r = tmp;
			r -> next = NULL;
		}else{
			tmp = q;
			q = q -> next;
			r -> next = tmp;
			r = tmp;
			r -> next = NULL;
		}
	}

	if(p != NULL)
		r -> next = p;
	if(q != NULL)
		r -> next = q;
	
	if(h -> next == NULL){
		printf("NULL\n");
		return;
	}
	
	printf("%d", h -> next -> data);
	h = h -> next;
	while(h -> next != NULL){
		printf(" %d", h -> next -> data);
		h = h -> next;
	}

	printf("\n");
	return;
}
