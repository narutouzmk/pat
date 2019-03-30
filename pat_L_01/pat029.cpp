#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

/*int main(void){

	string s1, s2;
	int pos;
	getline(cin, s1);
	getline(cin, s2);

	while((pos = s1.find(s2)) != string::npos)//找到s2在s1中第一次出现的首个字符位置，如果合法
		s1.replace(pos, s2.length(), "");//从找到的位置开始s2长度的字符串都用空串替代，完成一次删除
	cout<<s1<<endl;
	return 0;
}*/

int main(void){
	char s1[81];
	char s2[81];
	char t[80];
	char *p;

	gets(s1);
	gets(s2);
	while((p = strstr(s1, s2)) != NULL){
		strcpy(t, p + strlen(s2));
		*p = '\0';
		strcat(s1, t);
	}

	puts(s1);
	return 0;
}
