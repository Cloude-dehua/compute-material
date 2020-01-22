/**
登登考研团队
*/
#include <cstdio>
#include <cstring> 
const int maxn = 10000;
char s1[maxn], s2[maxn];
int m[maxn][maxn];
// m[i][j] 表示以s1[i]和s2[j]结尾公共子串长度 
// s1[i+1]==s2[j+1] : m[i+1][j+1] = m[i][j] + 1
// s1[i+1]!=s2[j+1] : m[i+1][j+1] = 0 

// 本质：如果看到有子问题重叠的时候，原问题的最有优是子问题的最优解构造起来的（可以写递推（状态转移方程））
// 形式：最长，最大，最多。。。 

 

int main() {
	while(scanf("%s%s", s1, s2)==2) {
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int maxlen = 0;	// 最长公共子串的长度 
		int p, q;	// 最长公共子串的尾坐标 
		for(int i=0; i<len1; i++) {
			for(int j=0; j<len2; j++) {
				if(s1[i]==s2[j]) {
					m[i][j] = ((i==0||j==0) ? 0 : m[i-1][j-1]) + 1;
					if(m[i][j]>maxlen) {	// 发现一个更长的 
						maxlen = m[i][j];
						p = i;
						q = j;	
					}	
				} else {
					m[i][j] = 0;
				}
			}
		}
		for(int i=maxlen-1; i>=0; i-- ) {
			printf("%c", s1[p-i]);
		}
		printf("\n"); 
	}
	return 0;
}

