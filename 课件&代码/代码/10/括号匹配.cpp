#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
char str[maxn];			// ���ʽ 
int main(){
	
	int n;
	scanf("%d", &n);
	while(n--) {
		stack<char> S;	// ջ
		scanf("%s", str);
		int len = strlen(str);
		int ok = 1;		// ����Ƿ���ƥ�� 
		for(int i=0; i<len; i++) {
			if(str[i]=='(' || str[i]=='[')	{	// �����ţ���ƥ�䣬��ջ 
				S.push(str[i]);		// ��ջ 
			} else if(str[i]==')') {		// ��С���� 
				if(!S.empty()) {			// ջ�ǿ�ʱ 
					if(S.top()=='(') {		// ��ƥ�� 
						S.pop();			// ��ջ 
					} else {				// ����ƥ�� 
						ok = 0;
						break;
					}
				} else {					// û�д�ƥ������� 
					ok = 0;
					break;
				}
			} else if(str[i]==']') {		// ��С���� 
				if(!S.empty()) {			// ջ�ǿ�ʱ 
					if(S.top()=='[') {		// ��ƥ�� 
						S.pop();			// ��ջ 
					} else {				// ����ƥ�� 
						ok = 0;
						break;
					}
				} else {					// û�д�ƥ������� 
					ok = 0;
					break;
				}
			}
		}
		ok = ok && S.empty();				// ƥ�������˳��������ƥ����û�ж���������� 
		printf("%s\n", ok?"Yes":"No");
	} 

	return 0;
}

