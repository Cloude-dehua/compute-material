/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

set<int> s;
// IΪȫ����nΪȫ����С��AΪ��ǰ���ϣ�curλA���ϵĴ�С 
void print_multi_permutation(int* I,int n, int* A, int cur) {
	if(cur==n) {
		// ��������� ȥ���ظ���A
		// ��A�������Ϊһ������ 
		int num = 0;
		for(int i=0; i<n; i++) {
			num = num * 10 + A[i];
		}
		if(s.find(num) == s.end()) {	// ֮ǰû�г��ֹ� 
			for(int i=0; i<n; i++) {
				printf("%d ", A[i]);
			}
			printf("\n");
			s.insert(num);	// ����
		 
		}
	} else {
		for(int i=0; i<n; i++) if(i==0 || (I[i] != I[i-1])){
			int c1 = 0; // ��ʾI[i] ������I�г��ֵĴ���
			int c2 = 0; // ��ʾI[i] �ڵ�ǰ���ϳ��ֵĴ���
			for(int j=0; j<n; j++) {
				if(I[i] == I[j]) c1++;
			}
			for(int j=0; j<cur; j++) {
				if(I[i] == A[j]) c2++;
			}  
			if(c1>c2) {	// ���Խ�I[i]��ӽ��� 
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

