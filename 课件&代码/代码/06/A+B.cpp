#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int parse(char* s, int len) {
// ������Ϊlen���ַ����ֽ���Ϊ��ͨ���� 
	int sign = 1;		// ���ű�� 
	if(s[0]=='-') {		// ����Ǹ��� 
		sign = -1;
	}
	int ans = 0;
	for(int i=0; i<len; i++) {	// ѭ���������� 
		if('0'<=s[i] && s[i]<='9') {	// �ַ����� 
			ans = ans*10 + s[i]-'0';	// ����int���� 
		}
	}
	return ans*sign;
} 

int main(){
	char s1[15], s2[15];
	while(scanf("%s%s", s1, s2)==2) {	// ѭ�������������
		printf("%d\n", parse(s1, strlen(s1)) + parse(s2, strlen(s2)));
	}

	return 0;
}

