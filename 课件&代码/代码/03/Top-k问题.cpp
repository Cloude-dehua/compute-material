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
// 在a[low, high]中找第k小
	if(low>high) return -1;	// 没有找到
	int prive = a[low];		// 枢轴元素
	int p = low, q = high;	// 前后扫描指针 
	while(p<q) {	// 还有元素需要划分 
		while(q>=low && a[q]>=prive) q--;	// 从后往前找一个比prive小的元素 
		a[p] = a[q];			// 将这个小元素移动到前面 
		while(p<=high && a[p]<=prive) p++;	 // 从前往前后一个比priveda的元素
		a[q] = a[p];
	} 
	a[p] = prive; 
	if(p==k) return a[p];	// 找到了
	if(k<p) return top_k(a, low, p-1, k);	// 去前部分找 
	else  return top_k(a, p+1, high, k);	// 去后部分找
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

