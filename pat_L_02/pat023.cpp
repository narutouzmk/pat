#include <iostream>

using namespace std;

int getHeight(char *pre, int l1, int r1, char *mid, int l2, int r2);

char pre[52];
char mid[52];

int main(void){
	int N, h;
	char c;

	cin >> N;

	for(int i = 1; i <= N; ++i){
		cin >> pre[i];
	}
	for(int i = 1; i <= N; ++i){
		cin >> mid[i];
	}

	h = getHeight(pre, 1, N, mid, 1, N);
	
	cout << h << endl;
	return 0;
}


int getHeight(char *pre, int l1, int r1, char *mid, int l2, int r2){
	int h1, h2, i;
	if(l1 > r1){
		return 0;
	}else{
		for(i = l2; i <= r2; ++i){
			if(mid[i] == pre[l1]){
				break;
			}
		}

		h1 = getHeight(pre, l1 + 1, l1 + i - l2, mid, l2 , i - 1);
		h2 = getHeight(pre, l1 + i - l2 + 1, r1, mid, i + 1, r2);
	}

	return (h1 > h2 ? h1 : h2) + 1;
}
