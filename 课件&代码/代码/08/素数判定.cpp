#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

bool isPrime(int x) {
// �ж�x�Ƿ�Ϊ���� 
	int m = (int)(sqrt(x)+0.5);
	for(int i=2; i<=m; i++) {		// �ж�[2, sqrt(x)]���Ƿ��������ܱ�x���� 
		if(x%i==0) return false;
	}
	return true;
}

int main(){
	int x, y;
	while(scanf("%d%d", &x, &y)==2 && !(x==0 && y==0)) {
		int ok = 1;	// ����������������ֵı��ʽֵ�������� 
		for(int i=x; i<=y; i++) {
			int n = i*i+i+41;
			if(!isPrime(n)) {
				ok = 0;
				break;
			}	
		}
		printf("%s\n", ok ? "OK":"Sorry"); 
	} 
	return 0;
}

