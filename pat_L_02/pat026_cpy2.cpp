#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char msg[11];
	int priority;
};

typedef struct Node *node;

struct{
	node heap[100000];
	int num;
} Heap;

void Put();
void Get();

int main(void){
	int n;
	scanf("%d", &n);
	Heap.heap[0] = (node)malloc(sizeof(struct Node));
	Heap.heap[0] -> priority = -1;
	Heap.num = 0;

	while(n--){
		char op[4];
		getchar();
		scanf("%s", op);
		switch(op[0]){
			case 'P':
				Put();
				break;
			case 'G':
				Get();
				break;
			default:
				break;
		}
	}

	return 0;
}

void Put(){
	int i;
	node temp = (node)malloc(sizeof(struct Node));
	scanf("%s %d", temp -> msg, &temp -> priority);
	for(i = ++Heap.num; Heap.heap[i/2]->priority > temp -> priority; i /= 2){
		Heap.heap[i] = Heap.heap[i/2];
	}
	Heap.heap[i] = temp;
}

void Get(){
	int i;

	if(Heap.num < 1){
		printf("EMPTY QUEUE!\n");
		return;
	}

	printf("%s\n", Heap.heap[1] -> msg);

	for(i = 1; i*2 < Heap.num;){
		if(i * 2 + 1 < Heap.num && Heap.heap[i * 2 + 1] -> priority < Heap.heap[i * 2] -> priority){
			if(Heap.heap[i * 2 + 1] -> priority < Heap.heap[Heap.num] -> priority){
				Heap.heap[i] = Heap.heap[i * 2 + 1];
				i = i * 2 + 1;
			}else{
				break;
			}
		}else{
			if(Heap.heap[i * 2] -> priority < Heap.heap[Heap.num] -> priority){
				Heap.heap[i] = Heap.heap[i * 2];
				i = i * 2;
			}else{
				break;
			}
		}
	}

	Heap.heap[i] = Heap.heap[Heap.num--];
}
