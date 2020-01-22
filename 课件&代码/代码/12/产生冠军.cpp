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
		map<string, int> m;		// s[i]保存入度,i被打败的次数 
		while(n--) {
			string a, b;
			cin>>a>>b;				// a打败b   a->b 
			if(m.find(a) == m.end()) m[a] = 0;	// 将第一次出现的a和b选手初试化 
			if(m.find(b) == m.end()) m[b] = 0;
			m[b]++;		// b的入度要加一 
		} 
		int zeroNum = 0;		// 入度为零的结点数量 
		for(map<string, int>::iterator it=m.begin(); it!=m.end(); it++) {	// 遍历map 
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

