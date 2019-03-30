#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MAXN 255

struct Score{
	int id;
	int au, al, p;
	double d1, d2;
}a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int N, M;

bool comp1(const Score &s1, const Score &s2);
bool comp2(const Score &s1, const Score &s2);
bool comp3(const Score &s1, const Score &s2);
bool comp4(const Score &s1, const Score &s2);

int main(void){
	int i, j;
	scanf("%d %d", &N, &M);

	for(i = 0; i < N; ++i){
		a[i].id = b[i].id = c[i].id = d[i].id = i;
		scanf("%d %d %d", &a[i].au, &a[i].al, &a[i].p);
		a[i].d1 = 1.0 * a[i].au / a[i].p;
		a[i].d2 = 1.0 * a[i].al / a[i].p;

		b[i].au = c[i].au = d[i].au = a[i].au;
		b[i].al = c[i].al = d[i].al = a[i].al;
		b[i].p = c[i].p = d[i].p = a[i].p;
		b[i].d2 = c[i].d2 = d[i].d2 = a[i].d2;
		b[i].d1 = c[i].d1 = d[i].d1 = a[i].d1;
	}

	sort(a, a+N, comp1);
	sort(b, b+N, comp2);
	sort(c, c+N, comp3);
	sort(d, d+N, comp4);

	for(int i = 0; i < M; ++i){
		int con;
		scanf("%d", &con);
		if(i){
			printf(" ");
		}
		int id = 1000, f;

		for(int j = 0; j < N; ++j){
			if(a[j].id == con){
				while(j >= 1 && a[j].au == a[j-1].au){
					--j;
				}
				if(j < id){
					id = j;
					f = 1;
				}
				break;
			}
		}

		for(int j = 0; j < N; ++j){
			if(b[j].id == con){
				while(j >= 1 && b[j].al == b[j-1].al){
					--j;
				}
				if(j < id){
					id = j;
					f = 2;
				}
				break;
			}
		}

		for(int j = 0; j < N; ++j){
			if(c[j].id == con){
				while(j >= 1 && c[j].d1 == c[j-1].d1){
					--j;
				}
				if(j < id){
					id = j;
					f = 3;
				}
				break;
			}
		}

		for(int j = 0; j < N; ++j){
			if(d[j].id == con){
				while(j >= 1 && d[j].d2 == d[j-1].d2){
					--j;
				}
				if(j < id){
					id = j;
					f = 4;
				}
				break;
			}
		}

		printf("%d:%d", id+1, f);
	}

	printf("\n");
	return 0;
}

bool comp1(const Score &s1, const Score &s2){
	if(s1.au == s2.au)
		return s1.id < s2.id;
	else
		return s1.au > s2.au;//定义谁放在数组前头
}

bool comp2(const Score &s1, const Score &s2){
	if(s1.al == s2.al){
		return s1.id < s2.id;
	}else{
		return s1.al > s2.al;
	}
}
bool comp3(const Score &s1, const Score &s2){
	if(s1.d1 == s2.d1){
		return s1.id < s2.id;
	}else{
		return s1.d1 > s2.d1;
	}
}
bool comp4(const Score &s1, const Score &s2){
	if(s1.d2 == s2.d2){
		return s1.id < s2.id;
	}else{
		return s1.d2 > s2.d2;
	}
}
