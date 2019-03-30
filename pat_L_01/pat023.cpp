#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char ans[100];

int main(void){
	bool b;
	int l, num, n, d;

	while(scanf("%d", &num) == 1){

		memset(ans, 0, sizeof(ans));

		d = 0;
		l = 0;
		b = true;
		
		if(num == 0){
			printf("a\n");
			continue;
		}

		while(num){
			n = num % 10;
			num = num / 10;

			if(d == 4){
				b = true;
				ans[l++] = 'W';
			}
			else if(d == 8){
				b =true;
				ans[l++] = 'Y';
			}

			if(b == false && n == 0){
				ans[l++] = 'a';
				b = true;
			}

			if(n){
				if(d % 4 == 1) ans[l++] = 'S';
				else if(d % 4 == 2) ans[l++] = 'B';
				else if(d % 4 == 3) ans[l++] = 'Q';

				b = false;

				if(!(d == 1 && n == 1))
					ans[l++] = 'a' + n;
			}

			d++;
		}

		reverse(ans, ans + l);
		printf("%s\n", ans);
	}

	return 0;
}
