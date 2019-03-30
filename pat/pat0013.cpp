#include <iostream>

using namespace std;

#define MAXSIZE 50

typedef int KeyType;

typedef struct ElemType{
	KeyType key;
}ElemType;

typedef struct SSTable{
	ElemType *R;
	int length;
}SSTable;

int Search_Bin(SSTable T, KeyType k);

void Create(SSTable &T){
	int i;
	T.R = new ElemType[MAXSIZE + 1];
	cin >> T.length;
	for(i = 1; i <= T.length; ++i)
		cin >> T.R[i].key;
}

KeyType main(){
	SSTable T;
	KeyType k;
	Create(T);
	cin >> k;
	KeyType pos = Search_Bin(T, k);
	if(pos)
		cout<<pos<<endl;
	else
		cout<<"NOT FOUND"<<endl;
	return 0;
}


KeyType Search_Bin(SSTable T, KeyType k){
	int left, mid, right;
	left = 1;
	right = T.length;
	while(left <= right){
		mid = (left + right) / 2;
		if(T.R[mid].key == k){
			return mid;
		}else if(T.R[mid].key > k){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}

	return 0;
}
