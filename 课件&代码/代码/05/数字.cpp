#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
char s[maxn];	// ���ַ����������ܡ������֡� 
int cnt[10];	// cnt[i]��������i���ֵĴ��� 
int main(){
	while(scanf("%s", s)==1) {
		int len = strlen(s);
		memset(cnt, 0, sizeof(cnt));	// ��ʼ��,���� 
		for(int i=0; i<len; i++) {		// ɨ������������֡� 
			cnt[s[i]-'0']++;		// ͳ��s[i]���ִ��� '0'->48, '1'->49   
		}
		int max = 0, ans;
		for(int i=0; i<10; i++) {	// ͳ��0-9�г��ִ������� 
			if(cnt[i]>max) {
				max = cnt[i];
				ans = i;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

