#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 55;
char s[maxn]; 
int main(){
	while(scanf("%s", s)==1) {
		int len = strlen(s);
		char pre; 
		for(int i=0; i<len; i++) {
			if(!('0'<=s[i] && s[i]<='9')) {	// ������ 
				printf("%c", s[i]);
				pre = s[i]; 
			} else {	// ���� 
				int num = 0;	// ����������� 
				while('0'<=s[i] && s[i]<='9') {		// ���������һֱ����������ѭ��s[i]�������� 
					num = num*10 + s[i] - '0';		// �������� 
					i++;
				}  
				for(int j=0; j<num-1; j++) {	// ��Ϊǰ���Ѿ������һ�Σ����num-1�� 
					printf("%c", pre);
				}
				i--;	// ��ǰs[i]�Ƿ����֣� ����forѭ����i++ 
			}
		}
		printf("\n");
	}

	return 0;
}

