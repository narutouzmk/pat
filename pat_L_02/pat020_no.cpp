#include <iostream>
#include <cstring>

using namespace std;
// ( *,/ +,- )
int isp[] = {0, 1, 5, 3, 6};
int icp[] = {0, 6, 4, 2, 1};

int getInPrior(char);
int getOutPrior(char);

int main(){
	char s[50], tmp;
	char stack[50], que[50];
	int top = -1, front = -1, rear = -1;
	int in_pri, out_pri;
	cin >> s;
	int len = strlen(s);
	for(int i = 0; i < len; ++i){
		tmp = s[i];
//		cout << "来的是:" << tmp << endl; //test
		if(tmp >= '0' && tmp <= '9'){
//			cout << "tmp是数字:" << tmp <<",直接入队" <<endl;//test
			++rear;
			que[rear] = tmp;
		}else if(rear == -1 && tmp == '-'){
			++rear;
			que[rear] = tmp;
		}else{
			if(top == -1){
//				cout << "tmp是字符"<<tmp<<",栈空,入栈"<<endl;//test
				++top;
				stack[top] = tmp;
			}else{//栈不空，而且来的字符是运算符
				char s = stack[top];//求当前栈顶运算符优先级
				
				in_pri = getInPrior(s);
				out_pri = getOutPrior(tmp);

				if(out_pri > in_pri){
//					cout << "tmp是字符"<<tmp<<"，优先级比"<<stack[top]<<"高,入栈"<<endl;//test
					++top;
					stack[top] = tmp;
				}else{//栈外优先级小于栈内优先级
					if(tmp == ')'){
//						cout << "tmp是右括号"<<tmp<<"，优先级比"<<stack[top]<<"低"<<endl;//test
						while(stack[top] != '(' && top > -1){
							char in_sT = stack[top];
//							cout << "栈顶元素:" << in_sT << "弹栈入队" <<endl;//test
							++rear;
							que[rear] = in_sT;
							--top;
						}
						if(top > 0)
							--top;
					}else{//来的不是右括号的字符，且优先级低于栈顶字符优先级
						
//						cout << "tmp不是右括号"<<tmp<<"，优先级比"<<stack[top]<<"低"<<endl;//test
						while(top > -1 && in_pri > out_pri){
							char in_sT = stack[top];
//							cout << "栈顶元素是:" << in_sT << "弹栈入队" << endl;
							--top;
							++rear;
							que[rear] = in_sT;
							if(top > -1){
								in_pri = getInPrior(stack[top]);
							}else{
								break;
							}
						}
						++top;
						stack[top] = tmp;
					}
				}
			}
		}
	}

	while(top > -1){
		char in_sT = stack[top];
		++rear;
		que[rear] = in_sT;
		--top;
	}

	++front;
	if(front <= rear){
		cout << que[front];
		++front;
		while(front <= rear){
			cout << " " <<que[front];
			++front;
		}
	}
	cout << endl;
	return 0;
}

int getInPrior(char c){
	int in_pri;
	switch(c){
		case '(':
			in_pri = 1;
			break;
		case '*':
		case '/':
			in_pri = 5;
			break;
		case '+':
		case '-':
			in_pri = 3;
			break;
		case ')':
			in_pri = 6;
			break;
	}
	return in_pri;
}
int getOutPrior(char c){
	int out_pri;
	switch(c){//求栈外优先级
		case '(':
			out_pri = 6;
			break;
		case '*':
		case '/':
			out_pri = 4;
			break;
		case '+':
		case '-':
			out_pri = 2;
			break;
		case ')':
			out_pri = 1;
			break;
	}
	return out_pri;
}
