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
			if(!('0'<=s[i] && s[i]<='9')) {	// 非数字 
				printf("%c", s[i]);
				pre = s[i]; 
			} else {	// 数字 
				int num = 0;	// 保存解析数字 
				while('0'<=s[i] && s[i]<='9') {		// 如果树数字一直解析，跳出循环s[i]不是数字 
					num = num*10 + s[i] - '0';		// 解析数字 
					i++;
				}  
				for(int j=0; j<num-1; j++) {	// 因为前面已经输出过一次，输出num-1次 
					printf("%c", pre);
				}
				i--;	// 当前s[i]是非数字， 抵消for循环的i++ 
			}
		}
		printf("\n");
	}

	return 0;
}

