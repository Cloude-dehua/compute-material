#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	char s1[10], s2[100];
	while(gets(s1)!=NULL && strcmp("#", s1)!=0) {
		gets(s2);				// 接收一行字符 
		int len1 = strlen(s1);	// 	求字符串长度 
		int len2 = strlen(s2);
		for(int i=0; i<len1; i++) {		// 遍历s1中的每个字符 
			int cnt = 0;
			for(int j=0; j<len2; j++) {	// 到s2中查找s1[i]出现次数 
				if(s1[i]==s2[j]) cnt++;
			} 
			printf("%c %d\n", s1[i], cnt);
		}
	}

	return 0;
}

