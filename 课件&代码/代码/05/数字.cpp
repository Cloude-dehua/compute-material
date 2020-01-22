#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
char s[maxn];	// 用字符数组来接受“大数字” 
int cnt[10];	// cnt[i]保存数字i出现的次数 
int main(){
	while(scanf("%s", s)==1) {
		int len = strlen(s);
		memset(cnt, 0, sizeof(cnt));	// 初始化,清零 
		for(int i=0; i<len; i++) {		// 扫描这个“大数字” 
			cnt[s[i]-'0']++;		// 统计s[i]出现次数 '0'->48, '1'->49   
		}
		int max = 0, ans;
		for(int i=0; i<10; i++) {	// 统计0-9中出现次数最多的 
			if(cnt[i]>max) {
				max = cnt[i];
				ans = i;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

