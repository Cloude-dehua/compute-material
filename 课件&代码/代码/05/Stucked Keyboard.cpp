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
int cnt[256];	// cnt[i]保存i(ASCII码)出现的连续次数 
int ok[256];	// ok[i]==1表示i是个“好”的字符 
int printed[256];	// printed[i]表示i已经被作为坏字符输出了 
int main(){
	int k;
	while(scanf("%d%s",&k, s)==2) {
		memset(ok, 0, sizeof(ok));		// 初始化
		memset(cnt, 0, sizeof(cnt)); 
		memset(printed, 0, sizeof(printed)); 
		int len = strlen(s);
		for(int i=0; i<len; i++) {
			cnt[s[i]]++;					// 统计连续出现次数 
			if(i+1<len && s[i]!=s[i+1]) {	// 当前字符和下一个字符不相等 
				if(cnt[s[i]]%k!=0) {
					ok[s[i]] = 1;
				}
				cnt[s[i]] = 0;				// 不连续了，清零，方便下次计数 
			}
		}
		if(cnt[s[len-1]]%k!=0) ok[s[len-1]] = 1;	// 判断最后一个字符 
		
		for(int i=0; i<len; i++) {		// 按检测顺序输出所有可能坏的字符 
			if(ok[s[i]]==0 && printed[s[i]]==0) {		// 可能是“坏”字符 
				printf("%c", s[i]);
				printed[s[i]] = 1;	// 已经输出 
			}
		}
		printf("\n");
		for(int i=0; i<len; i++) {
			printf("%c", s[i]);
			if(ok[s[i]]==0) i += k-1;		// 坏的字符每k个只输出一次，因为前面输出过一次了，剩下的k-1个跳过 
		}
		printf("\n");
	}

	return 0;
}

