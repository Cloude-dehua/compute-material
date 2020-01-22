#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int ss[55][110];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int m;
		scanf("%d", &m);
		int cnt = 0;		// ss[i]��Ԫ�صĸ��� 
		for(int j=0; j<m; j++) {
			int x;
			scanf("%d", &x);
			int flag = 0;		// ���x�Ƿ���ss[i]�� 
			for(int k=1; k<=cnt; k++) {	// ��ss[i]����x 
				if(ss[i][k]==x) {
					flag = 1;
					break;
				}
			}
			if(!flag) {
				ss[i][++cnt] = x; 
			}
		}
		ss[i][0] = cnt;		// ���泤�� 
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		int sameElem = 0;
		for(int i=1; i<=ss[a][0]; i++) {		// ö��a�����е�Ԫ�� 
			for(int j=1; j<=ss[b][0]; j++) {		// ö��b�����е�Ԫ��
				if(ss[a][i] == ss[b][j]) {		// �����ͬ 
					sameElem++;
				}
			}
		}
		int UElem = ss[a][0] + ss[b][0] - sameElem;
		printf("%.1lf%\n", 100.0 * sameElem/UElem);
	}

	return 0;
}

