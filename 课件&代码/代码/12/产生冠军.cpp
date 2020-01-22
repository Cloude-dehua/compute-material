#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int main(){
	
	int n;
	while(scanf("%d", &n)==1 && n) {
		map<string, int> m;		// s[i]�������,i����ܵĴ��� 
		while(n--) {
			string a, b;
			cin>>a>>b;				// a���b   a->b 
			if(m.find(a) == m.end()) m[a] = 0;	// ����һ�γ��ֵ�a��bѡ�ֳ��Ի� 
			if(m.find(b) == m.end()) m[b] = 0;
			m[b]++;		// b�����Ҫ��һ 
		} 
		int zeroNum = 0;		// ���Ϊ��Ľ������ 
		for(map<string, int>::iterator it=m.begin(); it!=m.end(); it++) {	// ����map 
			if(it->second == 0) {
				zeroNum++;
			}
		} 
		if(zeroNum==1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	
	return 0;
}

