#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int parse(char* s, int len) {
// 将长度为len的字符数字解析为普通数字 
	int sign = 1;		// 符号标记 
	if(s[0]=='-') {		// 如果是负号 
		sign = -1;
	}
	int ans = 0;
	for(int i=0; i<len; i++) {	// 循环解析数字 
		if('0'<=s[i] && s[i]<='9') {	// 字符数字 
			ans = ans*10 + s[i]-'0';	// 解析int数字 
		}
	}
	return ans*sign;
} 

int main(){
	char s1[15], s2[15];
	while(scanf("%s%s", s1, s2)==2) {	// 循环处理多组数据
		printf("%d\n", parse(s1, strlen(s1)) + parse(s2, strlen(s2)));
	}

	return 0;
}

