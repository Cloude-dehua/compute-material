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
int target[maxn];	// Ŀ���ջ���� 
int main(){
	int n;
	while(scanf("%d", &n)==1) {
		for(int i=1; i<=n; i++) scanf("%d", &target[i]);		// ��ջ����
		int A = 1, B = 1;
		stack<int> S;		// ģ����תվC 
		int ok = 1;
		while(B<=n) {		// ��ǰ˵Ҫ�õ���Ŀ�����л�û����� 
			if(!S.empty() && S.top() == target[B]) {	// ջ��Ԫ����Ŀ���ջ���У����ջ 
				S.pop();
				B++;
			} else if(A<=n) {	// ������г����ܹ���ջ 
				S.push(A);
				A++;
			} else {
				ok = 0;
				break;
			}
		} 
		if(ok) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		
		
	} 

	return 0;
}

