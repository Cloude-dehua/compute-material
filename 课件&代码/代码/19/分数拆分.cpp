/**
�ǵǿ����Ŷ�
*/
#include <cstdio>

int main() {
	int k, y;
	int kase = 1;
	while(scanf("%d", &k)==1) {
		printf("Case %d:\n", kase++);
		for(y=k+1; y<=2*k; y++) {	// ȷ��y��ö�ٷ�Χ 
			// x = y*k/(y-k) 
			if((y*k) % (y-k) == 0) {	// x������ 
				printf("1/%d=1/%d+1/%d\n", k, (y*k)/(y-k), y);
			}	
		}
	}
	return 0;
}

