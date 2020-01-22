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
char str[maxn];			// 表达式 
int main(){
	
	int n;
	scanf("%d", &n);
	while(n--) {
		stack<char> S;	// 栈
		scanf("%s", str);
		int len = strlen(str);
		int ok = 1;		// 标记是否能匹配 
		for(int i=0; i<len; i++) {
			if(str[i]=='(' || str[i]=='[')	{	// 左括号，待匹配，入栈 
				S.push(str[i]);		// 入栈 
			} else if(str[i]==')') {		// 右小括号 
				if(!S.empty()) {			// 栈非空时 
					if(S.top()=='(') {		// 能匹配 
						S.pop();			// 出栈 
					} else {				// 不能匹配 
						ok = 0;
						break;
					}
				} else {					// 没有带匹配的括号 
					ok = 0;
					break;
				}
			} else if(str[i]==']') {		// 右小括号 
				if(!S.empty()) {			// 栈非空时 
					if(S.top()=='[') {		// 能匹配 
						S.pop();			// 出栈 
					} else {				// 不能匹配 
						ok = 0;
						break;
					}
				} else {					// 没有带匹配的括号 
					ok = 0;
					break;
				}
			}
		}
		ok = ok && S.empty();				// 匹配过程中顺利，并且匹配完没有多余的左括号 
		printf("%s\n", ok?"Yes":"No");
	} 

	return 0;
}

