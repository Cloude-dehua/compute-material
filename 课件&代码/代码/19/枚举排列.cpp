/**
登登考研团队
*/
#include <cstdio>
#include <cstring>
const int maxn = 15;
int a[maxn]; 
int vis[maxn]; 
// A的待放入元素的集合，cur表示A有多少元素 
void print_permutation(int* A, int cur, int n) {
	if(cur==n) {	// A已经是全集
		// 输出A 
		for(int i=0; i<n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
	} else {	// A还不是全集，需要继续往A里面添加元素 
		for(int i=1; i<=n; i++) {	// 从小到大去添加元素到A集合 
			// 去检查i不在当前的A集合才能添加
			int ok = 1;
			for(int j=0; j<cur; j++) {
				if(A[j] == i) {
					ok = 0; 
					break;
				}
			} 
			if(ok) {	// i没有添加过（访问过） 
				A[cur] = i;
				print_permutation(A, cur+1, n);	// 继续递归添加下一个元素 
			}
		}
	}
}
// A的待放入元素的集合，cur表示A有多少元素 
void print_permutation2(int* A, int cur, int n) {
	if(cur==n) {	// A已经是全集
		// 输出A 
		for(int i=0; i<n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
	} else {	// A还不是全集，需要继续往A里面添加元素 
		for(int i=1; i<=n; i++) {	// 从小到大去添加元素到A集合 
			if(vis[i]==0) {	// i没有添加过（访问过） 
				A[cur] = i;
				vis[i] = 1;	// 标记i已经使用 
				print_permutation(A, cur+1, n);	// 继续递归添加下一个元素 
				vis[i] = 0;	// 特别要注意,cur这个位置不在放i,而是尝试放后面的数字，需要将vis[i]修改为0 
			}
		}
	}

}

int main() {
	int n;
	while(scanf("%d", &n)==1) {
//		print_permutation(a, 0, n);
		memset(vis, 0, sizeof(vis));
		print_permutation2(a, 0, n);
	}
	return 0;
}

