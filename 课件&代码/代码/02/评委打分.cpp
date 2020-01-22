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
	scanf("%d", &n);
	while(n-- > 0) {	// 已知n组数据 
		int sum =0, max=0, min=100, x;
		for(int i=0; i<7; i++) {	// 循环处理七个分数 
			scanf("%d", &x);
			sum += x;	// 累加
			if(x>max) max = x;	// 遇到更大更新
			if(x<min) min = x; 
		} 	
		sum = sum - min - max;	// 去掉最大最小值
		printf("%.1lf\n", sum/5.0); 
	} 
	return 0;
}

