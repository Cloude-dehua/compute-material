#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;	// �����ģ 
int a[maxn];				// ���飬ͨ������Ϊȫ�ֱ��� 
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	memset(a, 0, sizeof(a));		// ��ʼ������ֻ�ܳ�ʼ��Ϊ0����-1�������Ҫ��ʼ��Ϊ�������ݣ���forѭ�� 
	for(int i=1; i<=k; i++) {		// ģ��k���� 
		for(int j=i; j<=n; j+=i) {	// ��i������������Щi�ı����ĵ��� 
			a[j] = !a[j];			// �ı俪��״̬ 
		}
	} 
	for(int i=1; i<=n; i++) {		// ��� 
		if(a[i]) printf("%d ", i); 	
	} 
	
	return 0;
}

