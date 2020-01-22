#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

struct Fei{		// ���� 
	int up;		// ���� 
	int down;	// ��ĸ 
};

int gcd(int a, int b) {
// ��a��b�����Լ��
	return b==0 ? a : gcd(b, a%b);	
}

// a/b+c/d== (a*d+c*b)/b*d
Fei add(Fei a, Fei b) {
// ����a�ͷ���b��ӷ��غ�
	Fei sum; 
	sum.up = a.up*b.down + b.up*a.down;
	sum.down = a.down*b.down;
	// ����
	if(sum.up==0) sum.down = 1;
	if(sum.down<0) {	// ��ĸ�Ǹ������ӷ����Ƶ������� 
		sum.up = -sum.up;
		sum.down = -sum.down;
	} 
	// Լ�� 
	int m = gcd(abs(sum.up), abs(sum.down));	// ���Ӻͷ�ĸ�����Լ��
	sum.up /= m;
	sum.down /= m; 
	return sum;
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--) {	// ����t������ 
		int n;
		scanf("%d", &n);
		Fei ans = {0, 1}, tmp;
		for(int i=0; i<n; i++) {
			scanf("%d/%d", &tmp.up, &tmp.down);
			ans = add(ans, tmp); 
//			printf("ans = %d/%d\n", ans.up, ans.down);
		}
		// ���
		if(ans.up==0) printf("0\n");		// ����Ϊ0 
		else if(abs(ans.up) % ans.down==0) printf("%d\n", ans.up/ans.down);	// �������� 
		else if(abs(ans.up) > ans.down) printf("%d %d %d\n", ans.up/ans.down, abs(ans.up)%ans.down, ans.down); // ������ 
	 	else printf("%d %d\n", ans.up, ans.down);	// ��ͨ���� 
	}
	 
	return 0;
}

