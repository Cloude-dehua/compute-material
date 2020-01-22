/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
// �������취 
void print_subSet(int * A , int cur, int n) {
	// �����Ϳ��Խ�����·���ϵĽ��ȫ����ӡ 
	for(int i=0; i<cur; i++) {
		printf("%d ", A[i]);
	} 
	printf("\n");
	int s = cur==0? 1 : A[cur-1]+1;	// ö�ٵ���㣬��֤A���� 
	for(int i=s; i<=n; i++) {
		A[cur] = i;	// ��Ϊ��֤A�������������в���Ҫ���i�Ƿ���ǰ����ֹ� 
		print_subSet(A, cur+1, n);
	}
} 

// (1 0 0)--> {1}  (1 1 0) -{1, 2}   
// λ���������� 
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

// �����ƹ���    101010-->(2, 4, 6)  11001 ->(1,4,5)
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

