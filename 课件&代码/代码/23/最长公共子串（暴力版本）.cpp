/**
登登考研团队
*/
#include <cstdio>
#include <cstring> 
const int maxn = 10000;
char s1[maxn], s2[maxn];
int main() {
	while(scanf("%s%s", s1, s2)==2) {
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int p, q;
		int maxlen = 0;
		for(int i=0; i<len1; i++) {	// 考虑s1中起始点为i的子串 
			for(int j=0; j<len2; j++) {	// 考虑s2中起始点为j的子串 
				int len = 0;
				while(i+len<len1 && j+len<len2) {	
					if(s1[i+len] != s2[j+len]) {	// 末尾字符不相等 
						break;
					} else {	// 相等，子串长度再增加  
						len++;
						if(len>maxlen) {	// 找到一个更长的子串 
							maxlen = len;
							q = i;
							p = j;
						}
						
					}
				}
			}
		}
		for(int i=0; i<maxlen; i++) {
			printf("%c", s1[q+i]);
		}
		printf("\n");
		
	
	} 
	return 0;
}

