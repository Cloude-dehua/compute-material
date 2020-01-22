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
		int j=0;	// 最后保留的字符个数 
		for(int i=0; i<len; i++) {	// 扫描整个字符串 
			if(s[i]!='#' || (i-1>=0 && s[i-1]!='#')) {	// 非空格或者其前一个字符是非空格 需要保留 
				s[j++] = s[i];		// 移动到前面 
			}
		}
//		printf("j=%d\n", j);
		if(s[j-1]=='#') j--;	// 最后如果有行尾空格，要删除
		s[j] = '\0';			// 标记保留后的字符串结束了 
		printf("%s\n", s); 
	}

	return 0;
}

