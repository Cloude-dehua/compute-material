#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 10;
char s[maxn];
int main(){
	while(scanf("%s", s)==1) {
		int len = strlen(s);
		int ans = 0;
		// 思路一：枚举所有子串，判断该子串是否为回文串，时间复杂度为O(n^3) 
//		for(int i=0; i<len; i++) {		
//			for(int j=i; j<len; j++) {
//				// 得到当前子串s[i, j],然后判断是否为回文串
//				int ok = 1;		// 标记当前子串是否为回文串 
//				for(int p=i, q=j; p<=q; p++,q--) {
//					if(s[p] != s[q]) {
//						ok = 0;
//						break;
//					}
//				}
//				if(ok) ans++;	// 是回文串 
//			}
//		}

		// 思路二：利用子串之间的依赖关系，枚举所有串的中心点，从中心点往两端扩展，
		// 来判断更长的子串是否为回文串，时间复杂度为O(n^2) 
		for(int i=0; i<len; i++) {
			int num = 0;
			while(i-num>=0 && i+num<len && s[i+num] == s[i-num]) num++;	// 以i为中心，子串长度为奇数 
			ans += num;		// 累加回文子串数量 
			num = 0;		// 重新计数 
			while(i-num>=0 && i+1+num<len && s[i-num] == s[i+1+num]) num++;// 以i和i+1为中心，子串长度为偶数 
			ans += num;
		}

		printf("%d\n", ans); 
	}

	return 0;
}

