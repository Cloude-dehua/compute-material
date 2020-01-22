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
		double a, b, c;	// 三条边
		scanf("%lf%lf%lf", &a, &b, &c);
		if(a+b>c && a+c>b && b+c>a) {	// 任意的两边之和大于第三步，可以构成三角形 
			double q = (a+b+c)/2;
			printf("%.2lf\n", sqrt(q*(q-a)*(q-b)*(q-c)));
		}else {
			printf("0.00\n");
		}
	} 
	return 0;
}

