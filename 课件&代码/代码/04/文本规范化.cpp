#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
char s[maxn]; 
int main(){
	while(scanf("%s", s)==1) {
		int len = strlen(s);
		int j=0;	// ��������ַ����� 
		for(int i=0; i<len; i++) {	// ɨ�������ַ��� 
			if(s[i]!='#' || (i-1>=0 && s[i-1]!='#')) {	// �ǿո������ǰһ���ַ��Ƿǿո� ��Ҫ���� 
				s[j++] = s[i];		// �ƶ���ǰ�� 
			}
		}
//		printf("j=%d\n", j);
		if(s[j-1]=='#') j--;	// ����������β�ո�Ҫɾ��
		s[j] = '\0';			// ��Ǳ�������ַ��������� 
		printf("%s\n", s); 
	}

	return 0;
}

