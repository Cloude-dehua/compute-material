#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 20;
int a[1<<maxn];			// a���鱣�����нڵ��״̬��a[i]==0��ʾ�ر� 

int main(){
	int d, n;	// ����������Ⱥͺ�������
	while(scanf("%d%d", &d, &n)==2 && !(d==0 && n==0)) {
		memset(a, 0, sizeof(a));		// ��ʼ�����п��ض��ǹرյ�
		// ģ��n�ĺ���
		int k;
		for(int i=0; i<n; i++) {
			k = 1;				// ��ʾ��ǰ���ڽڵ㣬�������ڸ��ڵ��� 
			for(int j=1; j<d; j++) {	// ������d-1�� 
				a[k] = !a[k];		// �޸Ľڵ�״̬
				if(a[k]==1) {		// �޸�ǰ״̬Ϊ0�������� 
					k = 2*k;		// k�����ӱ�� 
				} else {			// ���� 
					k = 2*k+1;
				}
			} 	
		} 
		printf("%d\n", k);		//	���һ����������Ҷ�ӽڵ�ı�� 
		
	}

	return 0;
}

