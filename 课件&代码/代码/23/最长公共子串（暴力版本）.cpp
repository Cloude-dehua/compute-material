/**
�ǵǿ����Ŷ�
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
		for(int i=0; i<len1; i++) {	// ����s1����ʼ��Ϊi���Ӵ� 
			for(int j=0; j<len2; j++) {	// ����s2����ʼ��Ϊj���Ӵ� 
				int len = 0;
				while(i+len<len1 && j+len<len2) {	
					if(s1[i+len] != s2[j+len]) {	// ĩβ�ַ������ 
						break;
					} else {	// ��ȣ��Ӵ�����������  
						len++;
						if(len>maxlen) {	// �ҵ�һ���������Ӵ� 
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

