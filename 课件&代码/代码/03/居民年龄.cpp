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
	int age[101];	// age[i]��������Ϊi�ľ�������
	while(scanf("%d", &n)==1 && n) {
		int x;
		memset(age, 0, sizeof(age));	// ��ʼ��Ϊ0 
		for(int i=0; i<n; i++) {		// ͳ��n����������� 
			scanf("%d", &x);
			age[x]++;
		}
		for(int i=0; i<101; i++) {		// ��С�������age[i]��i(����) 
			for(int j=0; j<age[i]; j++) {
				printf("%d ", i);
			}
		}
		printf("\n");
	} 
	return 0;
}

