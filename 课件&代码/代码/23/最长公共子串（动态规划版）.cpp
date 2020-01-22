/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
#include <cstring> 
const int maxn = 10000;
char s1[maxn], s2[maxn];
int m[maxn][maxn];
// m[i][j] ��ʾ��s1[i]��s2[j]��β�����Ӵ����� 
// s1[i+1]==s2[j+1] : m[i+1][j+1] = m[i][j] + 1
// s1[i+1]!=s2[j+1] : m[i+1][j+1] = 0 

// ���ʣ�����������������ص���ʱ��ԭ�����������������������Ž⹹�������ģ�����д���ƣ�״̬ת�Ʒ��̣���
// ��ʽ����������ࡣ���� 

 

int main() {
	while(scanf("%s%s", s1, s2)==2) {
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int maxlen = 0;	// ������Ӵ��ĳ��� 
		int p, q;	// ������Ӵ���β���� 
		for(int i=0; i<len1; i++) {
			for(int j=0; j<len2; j++) {
				if(s1[i]==s2[j]) {
					m[i][j] = ((i==0||j==0) ? 0 : m[i-1][j-1]) + 1;
					if(m[i][j]>maxlen) {	// ����һ�������� 
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

