/**
登登考研团队
*/
#include <cstdio>
const int maxn = 100000;
int a[maxn];
int n;
void solve1() {
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);	
	}
	
	int maxSum = a[0];	// 默认最大子序列为第一个数字 
	int ansi = 0, ansj = 0; 
	// preSum[i] --- [0, i] 
	// preSum[j] - preSum[i-1]
	for(int i=0; i<n; i++) { // 枚举我们的子序列的开始和结尾[i, j] 
		for(int j=i; j<n; j++) {
			int sum = 0;	// 子序列的和 
			for(int k=i; k<=j; k++) {
				sum += a[k];	
			}
			if(sum>maxSum) {	// 发现更大的子序列和， 更新答案 
				maxSum = sum;
				ansi = i;
				ansj = j;
			}
		}
	}
	if(maxSum<0) printf("0 0 0\n"); 
	else printf("%d %d %d\n", maxSum, ansi, ansj);
}

void solve2() {
	int x;
	scanf("%d", &a[0]);
	for(int i=1; i<n; i++) {	// 求前缀和 
		scanf("%d", &x);
		a[i] = a[i-1] + x;
	}
	
	int maxSum = a[0];	// 默认最大子序列为第一个数字 
	int ansi = 0, ansj = 0; 
	// preSum[i] --- [0, i] 
	// preSum[j] - preSum[i-1]
	for(int i=0; i<n; i++) { // 枚举我们的子序列的开始和结尾[i, j] 
		for(int j=i; j<n; j++) {
			if(i > 0) {
				if(a[j]- a[i-1]>maxSum) {	// 发现更大的子序列和， 更新答案 
					maxSum = a[j]- a[i-1];
					ansi = i;
					ansj = j;
				}	
			} else {
				if(a[j]>maxSum) {	// 发现更大的子序列和， 更新答案 
					maxSum = a[j];
					ansi = i;
					ansj = j;
				}
			}
			
		}
	}
	if(maxSum<0) printf("0 0 0\n"); 
	else printf("%d %d %d\n", maxSum, ansi, ansj);
}

int main() {
	
	while(scanf("%d", &n) ==1 && n) {
		solve2();	
	}
	return 0;
}

