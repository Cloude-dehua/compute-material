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
	while(n-- > 0) {	// ��֪n������ 
		double a, b, c;	// ������
		scanf("%lf%lf%lf", &a, &b, &c);
		if(a+b>c && a+c>b && b+c>a) {	// ���������֮�ʹ��ڵ����������Թ��������� 
			double q = (a+b+c)/2;
			printf("%.2lf\n", sqrt(q*(q-a)*(q-b)*(q-c)));
		}else {
			printf("0.00\n");
		}
	} 
	return 0;
}

