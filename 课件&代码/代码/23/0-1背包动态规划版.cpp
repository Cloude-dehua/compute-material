/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m[22][2010];
int v[22], w[22]; 
int main() {
	// m[i][j] ��ʾ������Ϊj����״̬�¿���[0, i]�����ܻ�õ�����ֵ
	// m[i][j] = max(m[i-1][j-wi] + vi , m[i-1][j])  
	// m[3][20]��ʾ����Ϊ20������¿���[0,3]��һ������ܻ������ֵ 
	int n, c;
	while(scanf("%d%d", &n, &c)==2) {
		memset(m, 0, sizeof(m));
		for(int i=1; i<=n; i++)  scanf("%d", &w[i]);	// ������� 
		for(int i=1; i<=n; i++)  scanf("%d", &v[i]);	// ��ֵ����
		for(int i=1; i<=c; i++) printf("%4d", i); 
		printf("\n");
		for(int i=1; i<=n; i++) {	// ���ǵ�i����Ʒ�Ƿ����� 
			for(int j=1; j<=c; j++) {	//��ʾ������Ϊj����״̬�¿���[0, i]�����ܻ�õ�����ֵ
				if(j>=w[i])	// �ڵ�ǰ�������ڸ���Ʒ������ǣ��ſ������벻��������� 
					m[i][j] = max(m[i-1][j-w[i]] + v[i] , m[i-1][j]);
				else 	// �����i����Ʒ���� 
					m[i][j] = m[i-1][j];
//				printf("��%d����Ʒ����Ϊ%d�Ļ������ֵ") 
				printf("%4d", m[i][j]);
			}
			printf("\n");
		} 
		printf("%d\n", m[n][c]); 
		// ��θ���m���黹ԭ���з��� 
	}	 
	
	return 0;
}

