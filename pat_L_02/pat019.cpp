#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;

int main(void){
	LNode *head = (LNode *)malloc(sizeof(struct LNode));
	LNode *p, *q, *s;
	int a, n, count = 0;

	cin >> n;
	head -> next = NULL;
	head -> data = n;

	p = head;
	s = head;
	while((scanf("%d", &a) != EOF) && a > -1){
		q = (LNode *)malloc(sizeof(struct LNode));
		q -> data = a;
		q -> next = NULL;
		p -> next = q;
		p = q;
		++count;
		if(count >= n){
			s = s -> next;
		}
	}



	if(count >= n){
		cout << s -> data << endl;
	}else{
		cout << "NULL" << endl;
	}
	return 0;
}
