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
		int sum =0, max=0, min=100, x;
		for(int i=0; i<7; i++) {	// ѭ�������߸����� 
			scanf("%d", &x);
			sum += x;	// �ۼ�
			if(x>max) max = x;	// �����������
			if(x<min) min = x; 
		} 	
		sum = sum - min - max;	// ȥ�������Сֵ
		printf("%.1lf\n", sum/5.0); 
	} 
	return 0;
}

