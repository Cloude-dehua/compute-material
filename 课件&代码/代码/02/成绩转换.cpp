#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int score;	// ����
	while(scanf("%d", &score)==1) {	// ѭ������������� 
		if(108<=score && score<=120) printf("A\n");			// ���֧���������if.. else ifǶ�� 
		else if(100<=score && score<=107) printf("B\n");
		else if(80<=score && score<=99) printf("C\n");
		else if(72<=score && score<=79) printf("D\n");
		else if(0<=score && score<=71) printf("E\n");
		else printf("Score is error!\n");
	} 

	return 0;
}

