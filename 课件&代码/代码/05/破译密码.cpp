#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;		// 问题规模 
char s[maxn];

int main(){
	while(gets(s) && strcmp(s, "START")==0) {	// 接收消息头 
		gets(s);	// 密文
		int len = strlen(s);
		for(int i=0; i<len; i++) {	// 遍历密文并解析 
			if('A'<= s[i] && s[i]<='Z') {	// 大写字母 
				if(s[i]>='F') {			// 解析 
					printf("%c", s[i]-5);
				} else {
					printf("%c", s[i]+26-5);
				}
			} else {	// 非大写字母原文输出 
				printf("%c", s[i]);
			}
		} 
		printf("\n"); 
		gets(s);		// 接收END 
	}

	return 0;
}

