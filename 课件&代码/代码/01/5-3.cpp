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
	int flag = 1;	// ���Ʒ��� 
	do{
		if(flag) 
			pi += 1.0/i;
		else 
			pi -= 1.0/i;
		flag = !flag;	
		i += 2;	// ��ĸÿ������2 
	}while(1.0/i>=1e-6);		// ѭ������δ֪��ͨ��while������ 
	printf("%lf", 4*pi);
	return 0;
}

