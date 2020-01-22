/**
登登考研团队
*/
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

set<int> s;
// I为全集，n为全集大小，A为当前集合，cur位A集合的大小 
void print_multi_permutation(int* I,int n, int* A, int cur) {
	if(cur==n) {
		// 在这里控制 去掉重复的A
		// 对A数组编码为一个整数 
		int num = 0;
		for(int i=0; i<n; i++) {
			num = num * 10 + A[i];
		}
		if(s.find(num) == s.end()) {	// 之前没有出现过 
			for(int i=0; i<n; i++) {
				printf("%d ", A[i]);
			}
			printf("\n");
			s.insert(num);	// 加入
		 
		}
	} else {
		for(int i=0; i<n; i++) if(i==0 || (I[i] != I[i-1])){
			int c1 = 0; // 表示I[i] 在整个I中出现的次数
			int c2 = 0; // 表示I[i] 在当前集合出现的次数
			for(int j=0; j<n; j++) {
				if(I[i] == I[j]) c1++;
			}
			for(int j=0; j<cur; j++) {
				if(I[i] == A[j]) c2++;
			}  
			if(c1>c2) {	// 可以将I[i]添加进来 
				A[cur] = I[i];
				print_multi_permutation(I, n, A, cur+1);
			}
		}
	}
}
const int maxn = 10;
int a[maxn], b[maxn];
int main() {
	int n;
	while(scanf("%d", &n)==1) {
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
//		print_multi_permutation(a, n, b, 0);
		do{
			for(int i=0; i<n; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
		} while(next_permutation(a, a+n));
	}
	return 0;
}

