#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	
//	int tmp;	// 第三个临时变量
//	tmp = a;	// 将a的值赋值给tmp
//	a = b;		// 将b的值赋值给a,覆盖了a 
//	b = tmp;	// 将之前保留了a的tmp赋值给b
	
	printf("%d %d\n", b, a); 		// 取巧做法，只限OJ 

	return 0;
}

