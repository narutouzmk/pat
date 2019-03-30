#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MAXS 10001

struct GNode{
	int data;
	struct GNode *next;
}Graph[MAXS];

typedef struct GNode *PGNode;

int N, E;

PGNode que[MAXS];
int rear = -1, front = -1, size = 10001;
int visit[10001];

void link(int, int);
void initialize();
void sds();
int bfs(PGNode);
void EnQue(PGNode);
PGNode DeQue();

int main(void){
	cin >> N >> E;
	int v1, v2;
	int i;

	initialize();

	for(i = 0; i < E; ++i){
		cin >> v1 >> v2;
		link(v1, v2);
		link(v2, v1);
	}

	sds();
	return 0;
}

void sds(){
	int i, j, count = 0;

	for(i = 1; i <= N; ++i){
		for(j = 1; j <= N; ++j){
			visit[j] = 0;
		}

		rear = -1;
		front = -1;
		count = bfs(&Graph[i]);
		cout << i << ": " << setiosflags(ios::fixed) << setprecision(2) << 100.0 * ((double)count / N) <<"%"<<endl;
	}
}

int bfs(PGNode node){
	int tail, begin, end = node -> data, count = 1;
	int level = 0, i;

	EnQue(node);
	visit[node -> data] = 1;
	PGNode G = NULL;

	while(G = DeQue()){
		begin = G -> data;
		G = Graph[begin].next;
		while(G){
			i = G -> data;
			if(!visit[i]){
//				cout << "i=" << i <<" ";//test
				visit[i] = 1;
				EnQue(G);
				++count;
				tail = G -> data;
			}
			G = G -> next;
		}

		if(begin == end){
			++level;
			end = tail;
		}

		if(level == 6){
//			cout <<endl;//test
			break;
		}
	}

	return count;
}

void initialize(){
	int i;
	for(i = 1; i <= N; ++i){
		Graph[i].data = i;
		Graph[i].next = NULL;
	}
}

void link(int v1, int v2){
	PGNode G = &Graph[v1];
	while(G -> next){
		G = G -> next;
	}

	G -> next = (PGNode)malloc(sizeof(struct GNode));
	G -> next -> next = NULL;
	G -> next -> data = v2;
}

PGNode DeQue(){
	if(front == rear)
		return NULL;
	front = (front + 1) % size;
	return que[front];
}

void EnQue(PGNode G){
	rear = (rear + 1) % size;
	que[rear] = G;
}
