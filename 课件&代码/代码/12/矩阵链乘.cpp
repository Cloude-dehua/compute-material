#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;

struct Matrix{
	int r;		// �� 
	int c;		// �� 
}ss[27];

int main(){
	
	int n;
	scanf("%d", &n);
	char m[3];
	int r, c; 
	while(n--) {		// ����n��������Ϣ 
		scanf("%s%d%d", m, &r, &c);		// ���������
		ss[m[0]-'A'].r = r;
		ss[m[0]-'A'].c = c;
	}
	char str[100];	// �˷����ʽ 

	while(scanf("%s", str)==1) {
		int len = strlen(str);
		int ok = 1;			// ��ʼ�� 
		int ans = 0; 
		stack<Matrix> S;
		for(int i=0; i<len; i++) {
			if('A'<= str[i] && str[i]<='Z') {
				S.push(ss[str[i]-'A']);
			} else if(str[i] == ')') {	// �������ȼ��͵�')'��Ҫ�ȼ���˷� 
				Matrix y = S.top();		// ����ջ�� 
				S.pop(); 				// ����
				Matrix x = S.top();
				S.pop();
//				printf("%d==%d==%d==%d\n", x.r, x.c, y.r, y.c);
				if(x.c != y.r) {
					ok = 0;
					break;
				}
				ans += x.r*x.c*y.c;
				Matrix z = {x.r, y.c};
				S.push(z); 
			}
		} 
		if(ok) {
			printf("%d\n", ans);	
		} else {
			printf("error\n");
		}
	}
	return 0;
}

