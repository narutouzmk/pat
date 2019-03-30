#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAXN 100010

struct Information{
	char num[7];//长度应该为7，因为光数字就有6位，如果给6个位置,最后一个'\0'没法放，就会造成错误
	char name[8];
	int gload;
};

Information inf[MAXN];
int N, C;

bool comp1(const Information &st1, const Information &st2);
bool comp2(const Information &st1, const Information &st2);
bool comp3(const Information &st1, const Information &st2);

int main(void){
	scanf("%d %d", &N, &C);

	for(int i=0; i<N; ++i){
		scanf("%s %s %d", inf[i].num, inf[i].name, &inf[i].gload);//注释
	}

	if(C == 1){
		sort(inf, inf+N, comp1);
	}else if(C == 2){
		sort(inf, inf+N, comp2);
	}else if(C == 3){
		sort(inf, inf+N, comp3);
	}

	for(int i = 0; i < N; ++i){
		printf("%s %s %d\n", inf[i].num, inf[i].name, inf[i].gload);
	}
	return 0;
}

//定义小于
bool comp1(const Information &st1, const Information &st2){
	if(strcmp(st1.num, st2.num) < 0){
		return true;
	}else
		return false;
}

bool comp2(const Information &st1, const Information &st2){
	if(strcmp(st1.name, st2.name) < 0){
		return true;
	}else if(strcmp(st1.name, st2.name) > 0){
		return false;
	}else{
		if(strcmp(st1.num, st2.num) < 0){
			return true;
		}else
			return false;
	}
}

bool comp3(const Information &st1, const Information &st2){
	if(st1.gload < st2.gload){
		return true;
	}else if(st1.gload > st2.gload){
		return false;
	}else{
		if(strcmp(st1.num, st2.num) < 0){
			return true;
		}else
			return false;
	}
}
