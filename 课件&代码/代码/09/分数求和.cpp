#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

struct Fei{		// 分数 
	int up;		// 分子 
	int down;	// 分母 
};

int gcd(int a, int b) {
// 求a和b的最大公约数
	return b==0 ? a : gcd(b, a%b);	
}

// a/b+c/d== (a*d+c*b)/b*d
Fei add(Fei a, Fei b) {
// 分数a和分数b相加返回和
	Fei sum; 
	sum.up = a.up*b.down + b.up*a.down;
	sum.down = a.down*b.down;
	// 化简
	if(sum.up==0) sum.down = 1;
	if(sum.down<0) {	// 分母是负数，加符号移到分子上 
		sum.up = -sum.up;
		sum.down = -sum.down;
	} 
	// 约分 
	int m = gcd(abs(sum.up), abs(sum.down));	// 分子和分母的最大公约数
	sum.up /= m;
	sum.down /= m; 
	return sum;
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--) {	// 处理t组数据 
		int n;
		scanf("%d", &n);
		Fei ans = {0, 1}, tmp;
		for(int i=0; i<n; i++) {
			scanf("%d/%d", &tmp.up, &tmp.down);
			ans = add(ans, tmp); 
//			printf("ans = %d/%d\n", ans.up, ans.down);
		}
		// 输出
		if(ans.up==0) printf("0\n");		// 分子为0 
		else if(abs(ans.up) % ans.down==0) printf("%d\n", ans.up/ans.down);	// 可以整除 
		else if(abs(ans.up) > ans.down) printf("%d %d %d\n", ans.up/ans.down, abs(ans.up)%ans.down, ans.down); // 带分数 
	 	else printf("%d %d\n", ans.up, ans.down);	// 普通分数 
	}
	 
	return 0;
}

