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
	for(int i=1; i<=n ; i++) {		// ��forѭ�������� 
		if(i>1) printf(",");		// ������ĩ�ָ���ĳ����ֶ� 
		printf("%d", i);
	}
	return 0;
}

