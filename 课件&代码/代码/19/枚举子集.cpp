/**
登登考研团队
*/
#include <cstdio>
// 增量构造法 
void print_subSet(int * A , int cur, int n) {
	// 这样就可以将搜索路径上的结点全部打印 
	for(int i=0; i<cur; i++) {
		printf("%d ", A[i]);
	} 
	printf("\n");
	int s = cur==0? 1 : A[cur-1]+1;	// 枚举的起点，保证A升序 
	for(int i=s; i<=n; i++) {
		A[cur] = i;	// 因为保证A集合是升序，所有不需要检查i是否在前面出现过 
		print_subSet(A, cur+1, n);
	}
} 

// (1 0 0)--> {1}  (1 1 0) -{1, 2}   
// 位向量法构造 
void print_subSet2(int * A , int cur, int n) {
	if(cur==n) {
		for(int i=0; i<n; i++) {
			if(A[i] == 1) {
				printf("%d ", i+1);
			}
		}
		printf("\n");
	} else {
		A[cur] = 1;
		print_subSet2(A, cur+1, n);
		A[cur] = 0;
		print_subSet2(A, cur+1, n);
	}
}

// 二进制构造    101010-->(2, 4, 6)  11001 ->(1,4,5)
//	101010
//&   1000
//  001000
// 2^n 
void print_subSet3(int n) {
	for(int x=0; x<(1<<n); x++) {
		for(int i=0; i<n; i++) {
			if(x & (1<<i)) printf("%d ",i+1);
		}
		printf("\n");	
	}
}

const int maxn = 10;
int a[maxn];
int main() {
	int n; 
	while(scanf("%d", &n)==1) {
//		print_subSet(a, 0, n);
//		print_subSet2(a, 0, n);
		print_subSet3(n);
	}
	return 0;
}

