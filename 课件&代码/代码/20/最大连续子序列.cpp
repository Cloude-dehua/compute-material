/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
const int maxn = 100000;
int a[maxn];
int n;
void solve1() {
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);	
	}
	
	int maxSum = a[0];	// Ĭ�����������Ϊ��һ������ 
	int ansi = 0, ansj = 0; 
	// preSum[i] --- [0, i] 
	// preSum[j] - preSum[i-1]
	for(int i=0; i<n; i++) { // ö�����ǵ������еĿ�ʼ�ͽ�β[i, j] 
		for(int j=i; j<n; j++) {
			int sum = 0;	// �����еĺ� 
			for(int k=i; k<=j; k++) {
				sum += a[k];	
			}
			if(sum>maxSum) {	// ���ָ���������кͣ� ���´� 
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
	for(int i=1; i<n; i++) {	// ��ǰ׺�� 
		scanf("%d", &x);
		a[i] = a[i-1] + x;
	}
	
	int maxSum = a[0];	// Ĭ�����������Ϊ��һ������ 
	int ansi = 0, ansj = 0; 
	// preSum[i] --- [0, i] 
	// preSum[j] - preSum[i-1]
	for(int i=0; i<n; i++) { // ö�����ǵ������еĿ�ʼ�ͽ�β[i, j] 
		for(int j=i; j<n; j++) {
			if(i > 0) {
				if(a[j]- a[i-1]>maxSum) {	// ���ָ���������кͣ� ���´� 
					maxSum = a[j]- a[i-1];
					ansi = i;
					ansj = j;
				}	
			} else {
				if(a[j]>maxSum) {	// ���ָ���������кͣ� ���´� 
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

