#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 100 + 10;
int a[maxn];		// a���������������ǵ����� 
int n;				// ���� 
bool isSame() {
// �ж�n������������Ƿ�һ��
	for(int i=1; i<=n; i++) {
		if(a[i] != a[1]) return false;
	} 
	return true;
} 

int main(){
	
	while(scanf("%d", &n)==1) {
		for(int i=1; i<=n; i++) {	// ��ʼ��ÿ���������ǵ����� 
			scanf("%d", &a[i]);
		}
		int ans = 0;			// �����ǵ����� 
		while(!isSame()) {			// ���������е��ǲ���ȫһ������ģ����Ϸ 
			int tmp = a[1]; 		// a[1]��ǰ������� 
			// ��������Ƿ�һ������С�ģ�����1�ţ�
			for(int i=2; i<=n; i++) {
				a[i-1] += a[i]/2;
				a[i] /= 2; 
			} 
			a[n] += tmp/2;			// ��ǰa[1]��һ���� 
			a[1] -= tmp/2;			// a[1]�Լ��ó�������Ϸǰһ����� 
			
			// ������		
			for(int i=1; i<=n; i++) {
				if(a[i]%2==1) {		// ����������Ҫ���� 
					a[i]++;
					ans++;
				}
			} 
		} 
		printf("%d\n", ans); 
	}
	return 0;
}

