#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	for(int i=0; i<9; i++) {		// ������ 
		for(int j=0; j<i; j++) {	// ��ӡi��* 
			printf("*"); 
		}
		for(int j=9-i; j>=1; j--) {	// ��ӡ���� 
			printf("%d", j);
		}
		printf("\n");
	}

	return 0;
}

