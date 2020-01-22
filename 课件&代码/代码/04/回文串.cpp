#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 10;
char s[maxn];
int main(){
	while(scanf("%s", s)==1) {
		int len = strlen(s);
		int ans = 0;
		// ˼·һ��ö�������Ӵ����жϸ��Ӵ��Ƿ�Ϊ���Ĵ���ʱ�临�Ӷ�ΪO(n^3) 
//		for(int i=0; i<len; i++) {		
//			for(int j=i; j<len; j++) {
//				// �õ���ǰ�Ӵ�s[i, j],Ȼ���ж��Ƿ�Ϊ���Ĵ�
//				int ok = 1;		// ��ǵ�ǰ�Ӵ��Ƿ�Ϊ���Ĵ� 
//				for(int p=i, q=j; p<=q; p++,q--) {
//					if(s[p] != s[q]) {
//						ok = 0;
//						break;
//					}
//				}
//				if(ok) ans++;	// �ǻ��Ĵ� 
//			}
//		}

		// ˼·���������Ӵ�֮���������ϵ��ö�����д������ĵ㣬�����ĵ���������չ��
		// ���жϸ������Ӵ��Ƿ�Ϊ���Ĵ���ʱ�临�Ӷ�ΪO(n^2) 
		for(int i=0; i<len; i++) {
			int num = 0;
			while(i-num>=0 && i+num<len && s[i+num] == s[i-num]) num++;	// ��iΪ���ģ��Ӵ�����Ϊ���� 
			ans += num;		// �ۼӻ����Ӵ����� 
			num = 0;		// ���¼��� 
			while(i-num>=0 && i+1+num<len && s[i-num] == s[i+1+num]) num++;// ��i��i+1Ϊ���ģ��Ӵ�����Ϊż�� 
			ans += num;
		}

		printf("%d\n", ans); 
	}

	return 0;
}

