/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
int a[] = {100, 50, 20, 10, 5, 1};	// ��Ʊ��� 

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) ==2) {
		int cnt = 0; 
		int left = m - n;	// Ҫ�ҵ�Ǯ
		for(int i=0; i<6; i++) {	// ������ĳ�Ʊ���� 
//			while(left>=a[i]) {	// ������a[i] �ĳ�Ʊ 
//				left -= a[i];
//				cnt++;
//			}
			cnt += left / a[i];	// ֱ�Ӽ���Ҫ�Ҷ��������Ϊa[i]�ĳ�Ʊ 
			left %= a[i];	// �����ʣ�µ�Ǯ 
			if(left==0) break;
		} 
		printf("%d\n", cnt);
		
	}
	return 0;
}

