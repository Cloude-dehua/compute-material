#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int maxn = 55;
set<int> ss[maxn]; 
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int m, x;
		scanf("%d", &m);
		for(int j=0; j<m; j++) {
			scanf("%d", &x);
			if(ss[i].find(x) == ss[i].end()) {	// �ڵ�i��set����x������Ż�end()��ʾû���ҵ� 
				ss[i].insert(x);
			}
		}
	}	
	int q;
	scanf("%d", &q);
	while(q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--; 
		int sameElem = 0; 		// ����Ԫ�ظ��� 
		for(set<int>::iterator it = ss[a].begin(); it != ss[a].end(); it++) {	// �������� 
			if(ss[b].find(*it) != ss[b].end()) {  //����a�����е�Ԫ��it��b�����в��ң������b�У���Ϊ����Ԫ�� 
				sameElem++;					
			}
		}
		int UElem = ss[a].size() + ss[b].size() - sameElem;		// ��������
		printf("%.1lf%\n", 100.0 * sameElem/UElem); 
		
	}

	return 0;
}

