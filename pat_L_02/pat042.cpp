#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 1010

int N, P;
int vis[MAXN];
int table[MAXN];
int main(void){
	int flag = 0;

	memset(vis, -1, sizeof(vis));
	memset(table, 0, sizeof(table));

	scanf("%d %d", &N, &P);
	while(N--){
		int n, site;
		scanf("%d", &n);
		if(vis[n] != -1){
			if(!flag){
				printf("%d", vis[n]);
			}else{
				printf(" %d", vis[n]);
			}
			continue;
		}
		site = n % P;
		if(table[site] == 0){
			table[site] = 1;
			vis[n] = site;
			if(!flag){
				flag = 1;
				cout << site;
			}else{
				cout << " " <<site;
			}
		}else{
			for(int j = 1; j < P; ++j){
				if(table[ (site + j) % P] == 0){
					vis[n] = (site + j) % P;
					table[(site + j) % P] = 1;
					if(!flag){
						flag = 1;
						printf("%d", j);
					}else{
						printf(" %d", j);
					}
					break;
				}
			}
		}
	}
	printf("\n");
	return 0;
}
