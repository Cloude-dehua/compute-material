#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 100000 + 10;
int Left[maxn];			// left[i]==j ��ʾi��ǰ����j 
int Right[maxn]; 		// left[i]==j ��ʾi�ĺ����j
// ����1 3 5 4 6 2  
// left: 0 6 1 5 3 1
//Right: 3 0 5 6 4 2 

void link(int x, int y) {
// ����x��y��x��y�����
	Left[y] = x;
	Right[x] = y;	
}

int main(){
	int n,m;
	int kase = 1;
	while(scanf("%d%d", &n, &m)==2) {
		memset(Left, 0, sizeof(Left));
		memset(Left, 0, sizeof(Right));
		// ��ʼ��Left��Right����
		for(int i=1; i<=n; i++) {
			Left[i] = i-1;
			Right[i] = (i+1)%(n+1);		// Right[n] = 0������Ҫȡ�� 
		} 
		
		Left[0] = n;		// ��0��Ϊͷ��㣬�����ͱ��˫��ѭ������ 
		Right[0] = 1;
		int rev = 0;		// ��ǵ�ǰ�����Ƿ�ת����ת����ֻ�޸����ֵ�����߼��Ϸ�ת�� 
		int op, x, y; 
		while(m--) {		// ģ��m�β���
			 scanf("%d", &op);
			 if(op==4) {	// ��ת���� 
			 	rev = 1-rev;
			 } else {
			 	scanf("%d%d", &x, &y);	// ����x��y����
				if(rev && op<3) op = 3 - op;		// �ڷ�ת����£�x������y����ߺ��������x������y���ұ���ͬ 
				// 1 x y ���x�Ѿ���y���������Դ����� 
				if(op == 1 && x==Left[y]) continue;		// ����
				if(op == 2 && x==Right[y]) continue; 
			 	
			 	int lx = Left[x], rx = Right[x], ly = Left[y], ry = Right[y];	// �õ�x��y�����ҽ��
				if(op==1) {	// 1 x y ��ʾ�Ѻ���x�ƶ�������y�����   lx x rx...ly y ry ==> lx rx... ly x y ry
					link(lx, rx);
					link(ly, x);
					link(x, y);
				} else if(op ==2) {	// 2 x y ��ʾ�Ѻ���x�ƶ�������y���ұ� lx x rx...ly y ry ==> lx rx... ly y x ry
					link(lx, rx);
					link(y, x);
					link(x, ry);
				} else if(op == 3) {// 3 x y ��ʾ��������x��y��λ��
					if(Left[x] == y) {			//ly y x rx ==> ly x y rx
						link(ly, x);
						link(x, y);
						link(y, rx);
					} else if(Right[x] == y) {	//lx x y ry ==> lx y x ry 
						link(lx, y);
						link(y, x);
						link(x, ry);
					} else {					// lx x rx...ly y ry ==> lx y rx...ly x ry
						link(lx, y);
						link(y, rx);
						link(ly, x);
						link(x, ry);
					}
				}
			}
		}
		ll ans = 0;
		int j = 1;
		for(int i = Right[0]; i!=0 ; i = Right[i]) {	// ɨ���������� 
			if(j%2==1) {	// �ۼ�����λ�õ� 
				ans= ans + (ll)i;
			}
			j++;
		} 
		if(rev && n%2==0) {	// �ڷ�ת��Ԫ�ظ���Ϊż�����������żλ�ý��� 
			ans = (ll)n*(1+n)/2 - ans;
		}
		printf("Case %d: %lld\n",kase++, ans);
	}

	return 0;
}

