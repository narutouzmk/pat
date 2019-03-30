#include <iostream>
#include <cstdio>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

stack<double> st;

int main(void){
	string s;
	getline(cin, s);
	for(int i = s.size() - 1; i >= 0; --i){
		if(isdigit(s[i])){
			double num = s[i] - '0', mul = 10;
			for(i--; i >= 0; --i){
				if(isdigit(s[i])){
					num += (s[i] - '0') * mul;
					mul *= 10;
				}else if(s[i] == '.'){
					num /= mul;
					mul = 1;
				}else if(s[i] == '-'){
					num = -num;
				}else{
					break;
				}
			}
			st.push(num);
		}else if(s[i] != ' '){
			double a, b, sum;
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			switch(s[i]){
				case '+':
					sum = a + b;
					break;
				case '-':
					sum = a - b;
					break;
				case '*':
					sum = a * b;
					break;
				case '/':
					if(b == 0){
						cout << "ERROR" << endl;
						return 0;
					}else{
						sum = a / b;
					}
			}

			st.push(sum);
		}
	}

	printf("%.1lf\n", st.top());
	return 0;
}
