#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int n;
	while(scanf("%d", &n)==1) {
		int ans = n;		// 喝掉n瓶饮料，得到n个盖子 
		while(n>=3) {		// 盖子数量大于等于3,可以继续换饮料 
			ans += n/3;		// 这一次可以换的饮料
			n = n/3 + n%3;  // 饮料喝了得到盖子加上上次剩余的盖子 
		}
		printf("%d\n", ans); 
	} 

	return 0;
}

