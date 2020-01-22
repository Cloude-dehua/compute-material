#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 10;
int a[maxn];

int top_k(int* a, int low, int high, int k) {
// ��a[low, high]���ҵ�kС
	if(low>high) return -1;	// û���ҵ�
	int prive = a[low];		// ����Ԫ��
	int p = low, q = high;	// ǰ��ɨ��ָ�� 
	while(p<q) {	// ����Ԫ����Ҫ���� 
		while(q>=low && a[q]>=prive) q--;	// �Ӻ���ǰ��һ����priveС��Ԫ�� 
		a[p] = a[q];			// �����СԪ���ƶ���ǰ�� 
		while(p<=high && a[p]<=prive) p++;	 // ��ǰ��ǰ��һ����priveda��Ԫ��
		a[q] = a[p];
	} 
	a[p] = prive; 
	if(p==k) return a[p];	// �ҵ���
	if(k<p) return top_k(a, low, p-1, k);	// ȥǰ������ 
	else  return top_k(a, p+1, high, k);	// ȥ�󲿷���
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d", top_k(a, 0, n-1, k));
	return 0;
}

