#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

typedef struct MSG{
	char msg[15];
	int priority;
	friend bool operator < (MSG a, MSG b){
		return a.priority > b.priority;
	}
} MSG;

priority_queue<MSG> q;

int main(void){
	//freopen("xxx.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	MSG m;
	char op[15];

	for(int i = 0; i < n; ++i){
		scanf("%s", op);
		if(! strcmp(op, "PUT")){
			scanf("%s %d", m.msg, &m.priority);
			q.push(m);//注意push应该是m这个结构体的信息
		}else if(!strcmp(op, "GET")){
			if(q.empty()){
				printf("EMPTY QUEUE!\n");
			}else{
				MSG cur = q.top();
				q.pop();
				printf("%s\n", cur.msg);
			}
		}
	}

	return 0;
}
