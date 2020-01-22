#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int a[maxn];	// 初试状态
int b[maxn];	// 中间过程 

bool isSame(int* a, int* b, int len) {
// 判断a数组和b数组中的数据是否一样 
	for(int i=0; i<len; i++) {
		if(a[i]!=b[i]) return 0; 
	} 
	return 1;
}

int main(){
	int n;
	while(scanf("%d", &n)==1) {
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		// 先判断是否为插入排序
		bool isInsert = false;
		for(int i=1; i<n; i++) { // 将第i个数据插[0, i-1]使得[0, i]有序 
//			sort(a+0, a+i+1);
			for(int j=i; j>0; j--) {	// 依次往前插入 
				if(a[j] < a[j-1]) swap(a[j], a[j-1]);	// 如果比前面小则交换 
				else break;		// 否则已经排好了 
			} 
			if(isSame(a, b, n))	{	// 是插入排序 
				printf("Insertion Sort\n");
				while(isSame(a, b, n)) {	// 下一趟要求和b不一样 
					sort(a, a+i+1);
					i++;	
				}
				// 输出
				for(int i=0; i<n; i++) {
					if(i>0) printf(" ");
					printf("%d", a[i]);
				} 
				printf("\n");
				isInsert = true;
				break;
			}
		} 
		if(!isInsert) {
			printf("Heap Sort\n");
			// 确定排到第几趟了（即堆的大小）
			int k = n-1;	// k是堆的最后一个元素 
			while(b[k]>b[0]) k--;	 // 堆外的元素都大于根元素，堆内部的都小于根
			
			// 开始排下一趟 
			swap(b[0], b[k]);		// 根元素出堆
			k--;					// 堆大小减一 
			// 调整根元素
			int p = 0;	// 从更元素开始调整
			while(p<=k) {
				int max = p;	// max指向父节点和左右孩子中最大的那个
				if(2*p+1<=k && b[2*p+1]>b[p]) {
					max = 2*p+1;
				} 
				if(2*p+2<=k && b[2*p+2]>b[max]) {
					max = 2*p+2;
				}
				if(max==p) {	// 父节点比左右孩子都大，表示调整完
					break; 
				} else {
					swap(b[p], b[max]);	// 将父节点和较大的那个孩子做交换 
					p = max;			// p指向左右孩子中较大的那个 ，往下走
				}
				 
			}  
				// 输出
			for(int i=0; i<n; i++) {
				if(i>0) printf(" ");
				printf("%d", b[i]);
			} 
			printf("\n");
		}
	}

	return 0;
}

