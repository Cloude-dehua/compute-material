#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int a[maxn];	// ����״̬
int b[maxn];	// �м���� 

bool isSame(int* a, int* b, int len) {
// �ж�a�����b�����е������Ƿ�һ�� 
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
		// ���ж��Ƿ�Ϊ��������
		bool isInsert = false;
		for(int i=1; i<n; i++) { // ����i�����ݲ�[0, i-1]ʹ��[0, i]���� 
//			sort(a+0, a+i+1);
			for(int j=i; j>0; j--) {	// ������ǰ���� 
				if(a[j] < a[j-1]) swap(a[j], a[j-1]);	// �����ǰ��С�򽻻� 
				else break;		// �����Ѿ��ź��� 
			} 
			if(isSame(a, b, n))	{	// �ǲ������� 
				printf("Insertion Sort\n");
				while(isSame(a, b, n)) {	// ��һ��Ҫ���b��һ�� 
					sort(a, a+i+1);
					i++;	
				}
				// ���
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
			// ȷ���ŵ��ڼ����ˣ����ѵĴ�С��
			int k = n-1;	// k�Ƕѵ����һ��Ԫ�� 
			while(b[k]>b[0]) k--;	 // �����Ԫ�ض����ڸ�Ԫ�أ����ڲ��Ķ�С�ڸ�
			
			// ��ʼ����һ�� 
			swap(b[0], b[k]);		// ��Ԫ�س���
			k--;					// �Ѵ�С��һ 
			// ������Ԫ��
			int p = 0;	// �Ӹ�Ԫ�ؿ�ʼ����
			while(p<=k) {
				int max = p;	// maxָ�򸸽ڵ�����Һ����������Ǹ�
				if(2*p+1<=k && b[2*p+1]>b[p]) {
					max = 2*p+1;
				} 
				if(2*p+2<=k && b[2*p+2]>b[max]) {
					max = 2*p+2;
				}
				if(max==p) {	// ���ڵ�����Һ��Ӷ��󣬱�ʾ������
					break; 
				} else {
					swap(b[p], b[max]);	// �����ڵ�ͽϴ���Ǹ����������� 
					p = max;			// pָ�����Һ����нϴ���Ǹ� ��������
				}
				 
			}  
				// ���
			for(int i=0; i<n; i++) {
				if(i>0) printf(" ");
				printf("%d", b[i]);
			} 
			printf("\n");
		}
	}

	return 0;
}

