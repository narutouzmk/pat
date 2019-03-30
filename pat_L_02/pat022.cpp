#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAXS 1000
#define ERROR 0

typedef int ElementType;

struct Stack{
	int top;
	int size;
	ElementType st[MAXS];
};

typedef struct Stack *stack; 
typedef struct Item Item;

stack st1;//输入栈
stack st2;//输出栈

int IsFull(stack s);
int IsEmpty(stack s);
void Push(stack s, ElementType item);
ElementType Pop(stack s);

void AddQ(ElementType item);
int DeleteQ();

int main(void){
	int N1, N2;
	ElementType data;
	char op;

	cin >> N1 >> N2;

	st1 = (struct Stack *)malloc(sizeof(struct Stack));
	st2 = (struct Stack *)malloc(sizeof(struct Stack));

	if(N1 > N2){
		int tmp = N2;
		N2 = N1;
		N1 = tmp;
	}

	st1 -> top = -1;
	st1 -> size = N1;

	st2 -> top = -1;
	st2 -> size = N2;

	while((cin >> op) && (op != 'T')){
		ElementType a, data;
		switch(op){
			case 'A':
				cin >> data;
				AddQ(data);
				break;
			case 'D':
				a = DeleteQ();
				if(a == ERROR){
					cout << "ERROR:Empty" << endl;
				}else{
					cout << a << endl;
				}
				break;
		}
	}

	return 0;
}


void AddQ(ElementType item){
	if(!IsFull(st1)){
		Push(st1, item);
	}else if(IsEmpty(st2)){	
		while(!IsEmpty(st1)){
			int a = Pop(st1);
			Push(st2, a);
		}
		Push(st1, item);
	}else{
		cout << "ERROR:Full" << endl;
	}
}

ElementType DeleteQ(){
	ElementType a;

	if(!IsEmpty(st2)){
		a = Pop(st2);
		return a;
	}else if(!IsEmpty(st1)){
		while(!IsEmpty(st1)){
			a = Pop(st1);
			Push(st2, a);
		}
		a = Pop(st2);
		return a;
	}
	return ERROR;
}

int IsFull(stack s){
	if(s -> top == s -> size - 1){
		return 1;
	}
	return 0;
}

int IsEmpty(stack s){
	if(s -> top == -1){
		return 1;
	}
	return 0;
}

int Pop(stack s){
	if(s -> top > -1){
		ElementType a = s -> st[s -> top];
		--(s -> top);
		return a;
	}
	return 0;
}

void Push(stack s, ElementType item){
	if(s -> top < s -> size - 1){
		++(s -> top);
		s -> st[s -> top] = item;
	}
}
