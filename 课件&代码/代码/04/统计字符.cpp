#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	char s1[10], s2[100];
	while(gets(s1)!=NULL && strcmp("#", s1)!=0) {
		gets(s2);				// ����һ���ַ� 
		int len1 = strlen(s1);	// 	���ַ������� 
		int len2 = strlen(s2);
		for(int i=0; i<len1; i++) {		// ����s1�е�ÿ���ַ� 
			int cnt = 0;
			for(int j=0; j<len2; j++) {	// ��s2�в���s1[i]���ִ��� 
				if(s1[i]==s2[j]) cnt++;
			} 
			printf("%c %d\n", s1[i], cnt);
		}
	}

	return 0;
}

