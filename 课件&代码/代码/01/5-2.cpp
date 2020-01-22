#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	for(int i=1; ;i++) {	// 枚举所有i的平方 
		int m = i*i;
		if(m<1000) continue;	// continue可以跳过本轮循环
		if(m>10000) break;		// break跳出整个循环 
		
		int aa = m/100;			// 千位和百位
		int bb = m%100;			// 个位和十位
		if(aa%10 == aa/10 && bb%10 == bb/10) {
			printf("%d\n", m);
		}
	} 

	return 0;
}

