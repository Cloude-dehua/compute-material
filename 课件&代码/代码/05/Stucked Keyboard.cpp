#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1000 + 10;
char s[maxn];
int cnt[256];	// cnt[i]����i(ASCII��)���ֵ��������� 
int ok[256];	// ok[i]==1��ʾi�Ǹ����á����ַ� 
int printed[256];	// printed[i]��ʾi�Ѿ�����Ϊ���ַ������ 
int main(){
	int k;
	while(scanf("%d%s",&k, s)==2) {
		memset(ok, 0, sizeof(ok));		// ��ʼ��
		memset(cnt, 0, sizeof(cnt)); 
		memset(printed, 0, sizeof(printed)); 
		int len = strlen(s);
		for(int i=0; i<len; i++) {
			cnt[s[i]]++;					// ͳ���������ִ��� 
			if(i+1<len && s[i]!=s[i+1]) {	// ��ǰ�ַ�����һ���ַ������ 
				if(cnt[s[i]]%k!=0) {
					ok[s[i]] = 1;
				}
				cnt[s[i]] = 0;				// �������ˣ����㣬�����´μ��� 
			}
		}
		if(cnt[s[len-1]]%k!=0) ok[s[len-1]] = 1;	// �ж����һ���ַ� 
		
		for(int i=0; i<len; i++) {		// �����˳��������п��ܻ����ַ� 
			if(ok[s[i]]==0 && printed[s[i]]==0) {		// �����ǡ������ַ� 
				printf("%c", s[i]);
				printed[s[i]] = 1;	// �Ѿ���� 
			}
		}
		printf("\n");
		for(int i=0; i<len; i++) {
			printf("%c", s[i]);
			if(ok[s[i]]==0) i += k-1;		// �����ַ�ÿk��ֻ���һ�Σ���Ϊǰ�������һ���ˣ�ʣ�µ�k-1������ 
		}
		printf("\n");
	}

	return 0;
}

