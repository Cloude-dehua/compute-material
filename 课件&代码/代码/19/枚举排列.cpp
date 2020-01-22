/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
#include <cstring>
const int maxn = 15;
int a[maxn]; 
int vis[maxn]; 
// A�Ĵ�����Ԫ�صļ��ϣ�cur��ʾA�ж���Ԫ�� 
void print_permutation(int* A, int cur, int n) {
	if(cur==n) {	// A�Ѿ���ȫ��
		// ���A 
		for(int i=0; i<n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
	} else {	// A������ȫ������Ҫ������A�������Ԫ�� 
		for(int i=1; i<=n; i++) {	// ��С����ȥ���Ԫ�ص�A���� 
			// ȥ���i���ڵ�ǰ��A���ϲ������
			int ok = 1;
			for(int j=0; j<cur; j++) {
				if(A[j] == i) {
					ok = 0; 
					break;
				}
			} 
			if(ok) {	// iû����ӹ������ʹ��� 
				A[cur] = i;
				print_permutation(A, cur+1, n);	// �����ݹ������һ��Ԫ�� 
			}
		}
	}
}
// A�Ĵ�����Ԫ�صļ��ϣ�cur��ʾA�ж���Ԫ�� 
void print_permutation2(int* A, int cur, int n) {
	if(cur==n) {	// A�Ѿ���ȫ��
		// ���A 
		for(int i=0; i<n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
	} else {	// A������ȫ������Ҫ������A�������Ԫ�� 
		for(int i=1; i<=n; i++) {	// ��С����ȥ���Ԫ�ص�A���� 
			if(vis[i]==0) {	// iû����ӹ������ʹ��� 
				A[cur] = i;
				vis[i] = 1;	// ���i�Ѿ�ʹ�� 
				print_permutation(A, cur+1, n);	// �����ݹ������һ��Ԫ�� 
				vis[i] = 0;	// �ر�Ҫע��,cur���λ�ò��ڷ�i,���ǳ��Էź�������֣���Ҫ��vis[i]�޸�Ϊ0 
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

