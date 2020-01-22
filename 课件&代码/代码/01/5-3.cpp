#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	double pi = 0;
	int i = 1;
	int flag = 1;	// 控制符合 
	do{
		if(flag) 
			pi += 1.0/i;
		else 
			pi -= 1.0/i;
		flag = !flag;	
		i += 2;	// 分母每次增加2 
	}while(1.0/i>=1e-6);		// 循环次数未知，通过while来处理 
	printf("%lf", 4*pi);
	return 0;
}

