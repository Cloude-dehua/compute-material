#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;		// �����ģ 
char s[maxn];

int main(){
	while(gets(s) && strcmp(s, "START")==0) {	// ������Ϣͷ 
		gets(s);	// ����
		int len = strlen(s);
		for(int i=0; i<len; i++) {	// �������Ĳ����� 
			if('A'<= s[i] && s[i]<='Z') {	// ��д��ĸ 
				if(s[i]>='F') {			// ���� 
					printf("%c", s[i]-5);
				} else {
					printf("%c", s[i]+26-5);
				}
			} else {	// �Ǵ�д��ĸԭ����� 
				printf("%c", s[i]);
			}
		} 
		printf("\n"); 
		gets(s);		// ����END 
	}

	return 0;
}

