#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

/*****递归******/
/*void han(char, char, char, int);
void move(char, char);*/

/*****非递归****/
bool move(int, int);

stack<int> a[4];
char s[4] = {'q', 'a', 'b', 'c'};

int main(void){
	int N, count = 0;
	cin >> N;

	for(int i = 0; i < N; ++i){
		a[1].push(N - i);
	}

	if(N % 2 == 1){
		s[2] = 'c';
		s[3] = 'b';
	}

	while(++count){
		move((count - 1) % 3 + 1, count % 3 + 1);
		if(!move((count - 1) % 3 + 1, (count + 1) % 3 + 1) && !move((count + 1) % 3 + 1, (count - 1) % 3 + 1))
			break;
	}

	return 0;
}

/******递归*****/
/*
void han(char x, char y, char z, int n){
	if(n == 1)
		move(x, z);
	else{
		han(x, z, y, n - 1);
		move(x, z);
		han(y, x, z, n - 1);
	}
}

void move(char a, char b){
	cout << a << "->" << b << endl;
}*/


/******非递归*****/
bool move(int before,int after){
	if(a[before].empty()){
		return false;
	}

	if(!a[after].empty()){
		if(a[before].top() > a[after].top()){
			return false;
		}
	}

	a[after].push(a[before].top());
	a[before].pop();
	printf("%c -> %c\n", s[before], s[after]);
	return true;
}
