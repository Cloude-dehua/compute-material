#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
int b[maxn];	// �μӸ����˵ķ�������
int cnt = 0;	// �μӸ����˵����� 

bool cmp(int a, int b) {
	return a>b;		// ���� 
}

int main(){
	int n;			// �μӳ��Ե����� 
	scanf("%d", &n);
	int line[5];	// ���������
	for(int i=0; i<5; i++) scanf("%d", &line[i]);
	for(int i=0; i<n; i++) {	// ����n��ͬѧ 
		int a[5];
		a[4] = 0;	// �ܷ� 
		for(int i=0; i<4; i++) {
			scanf("%d", &a[i]);
			a[4] += a[i];		// �ۼӵ��Ƴɼ� 
		}
		bool ok = 1;		// ��ǵ�ǰ�����Ƿ��ܽ��븴�� 
		for(int i=0; i<5; i++) {
			if(a[i] < line[i]) {	// ��i��û�й��� 
				ok = 0;
				break;
			}
		}
		if(ok) {	// ���븴�� 
			b[cnt++] = a[4];
		} 
	} 
	
	sort(b, b+cnt, cmp);		// ����cmp��������b[0, cnt)����û��cmp������ 
	// ������� 
//	for(int i=cnt-1; i>=0; i--) {
//		printf("%d\n", b[i]);	
//	}
	for(int i=0; i<cnt; i++) {
		printf("%d\n", b[i]);
	} 
	return 0;
}

