/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
const int maxn = 60;
int a[maxn];
int main() {
	int n;
	while(scanf("%d", &n)==1) {
		for(int i=0; i<n; i++) scanf("%d", &a[i]);
		int cnt = 1;
		bool ok = false;
		for(int i=1; i<n; i++) {
			if(a[i]*a[0]<0) {	// �������е����Ϸ���һ��	
				ok = true; 
			}
			if(a[0]>0) {	// ��һֻ�����ң� 
				if(a[i]>0 && a[i]<a[0]) {	//  ������ߵĳ���
					cnt++;
				} else if(a[i]<0 && -a[i] > a[0]) {	// �������ұߵĳ���
					cnt++;
				}
			} else if(a[0]<0) { // ���� 
				if(a[i]<0 && a[i]<a[0]) { // ���ұ߳���
					cnt++;
				}  
				else if(a[i]>0 && a[i]<(-a[0])) { // ������߳��� 
					cnt++;
				}
			}
		}
		if(ok) printf("%d\n", cnt);
		else printf("1\n");
	}
	return 0;
}

