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
int target[maxn];	// 目标出栈序列 
int main(){
	int n;
	while(scanf("%d", &n)==1) {
		for(int i=1; i<=n; i++) scanf("%d", &target[i]);		// 出栈序列
		int A = 1, B = 1;
		stack<int> S;		// 模拟中转站C 
		int ok = 1;
		while(B<=n) {		// 当前说要得到的目标序列还没有完成 
			if(!S.empty() && S.top() == target[B]) {	// 栈顶元素是目标出栈序列，则出栈 
				S.pop();
				B++;
			} else if(A<=n) {	// 如果还有车厢能够入栈 
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

